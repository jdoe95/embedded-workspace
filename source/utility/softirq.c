/*
 * SoftIRQ for Deferring Work
 */
#include <utility/softirq.h>
#include <platform/contend.h>



#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
/* intentionally left blank */

#elif defined(__GNUC__)
/* intentionally left blank */

#else
/*
 * Needs critical section because neither has C11 atomics nor compiler atomics.
 */
#	include <platform/critical.h>
#endif



/*
 * Initializes a SoftIRQ instance
 */
void softirq_init(struct softirq_inst *inst, struct softirq_status *vec_status,
		void (*const *vec_action)(void), size_t num_vec)
{
	CONTEND(inst != NULL);
	CONTEND((num_vec == 0) || (vec_status != NULL));
	CONTEND((num_vec == 0) || (vec_action != NULL));

	for (size_t irq = (size_t) 0; irq < num_vec; ++irq)
	{
		/*
		 * Sequentially consistent model guarantees previous modifications of all related and
		 * unrelated variables are observable after the observation of a modification.
		 */
#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
		atomic_flag_test_and_set_explicit(&vec_status[irq].is_inactive, memory_order_seq_cst);
#else
		vec_status[irq].is_inactive = true;
#endif
	}

	inst->vec_action = vec_action;
	inst->vec_status = vec_status;
	inst->num_vec = num_vec;
}



/*
 * Pends a SoftIRQ vector
 * THIS FUNCTION SUPPORTS CONCURRENCY.
 */
void softirq_pend(struct softirq_inst *inst, size_t irq)
{
	CONTEND(inst != NULL);
	CONTEND(irq < inst->num_vec);
	CONTEND(inst->vec_status != NULL);

#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
	/*
	 * Sequentially consistent model guarantees previous modifications of all related and unrelated
	 * variables are observable after the observation of a modification.
	 */
	atomic_flag_clear_explicit(&inst->vec_status[irq].is_inactive, memory_order_seq_cst);

#elif defined(__GNUC__)
	/*
	 * Does not support C11 atomic but compiled with GCC, which has built-in atomics equivalent to
	 * those in C11.
	 */
	__atomic_clear(&inst->vec_status[irq].is_inactive, __ATOMIC_SEQ_CST);

#else
	/*
	 * No atomics whatsoever. Lock interrupts.
	 */

	struct irq_state state;

	irq_save_and_barrier(&state);
	inst->vec_status[irq].is_inactive = false;
	irq_restore_and_barrier(&state);
#endif
}



/*
 * Services the highest priority pending SoftIRQ
 * THIS FUNCTION SUPPORTS CONCURRENCY.
 */
void softirq_serve_one(struct softirq_inst *inst)
{
	CONTEND(inst != NULL);
	CONTEND((inst->num_vec == 0) || (inst->vec_action != NULL));
	CONTEND((inst->num_vec == 0) || (inst->vec_status != NULL));

	for (size_t index = (size_t) 0; index < inst->num_vec; ++index)
	{
		/*
		 * The atomic functions read softirq_status::is_inactive and sets it in one operation and
		 * returns the read result, which is then negated to is_pending.
		 */

#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
		bool is_pending = !atomic_flag_test_and_set_explicit(&inst->vec_status[index].is_inactive,
			memory_model_seq_cst);

#elif defined(__GNUC__)
		bool is_pending = !__atomic_test_and_set(&inst->vec_status[index].is_inactive,
			__ATOMIC_SEQ_CST);

#else
		struct irq_state state;

		irq_save_and_barrier(&state);
		bool is_pending = !inst->vec_status[irq].is_inactive;
		inst->vec_status[irq].is_inactive = true;
		irq_restore_and_barrier(&state);
#endif

		if (is_pending)
		{
			/* has IRQ vector action callback */
			if (inst->vec_action[index] != NULL)
			{
				inst->vec_action[index]();

				/* only serves 1 interrupt and breaks. */
				break;
			}
		}
	}
}

