/***************************************************************************************************
 * SoftIRQ for Deferring Work
 *
 * Complex interrupt handlers are separated into two halves. The top half is invoked by the CPU
 * hardware upon an interrupt. The top half is very time sensitive and exits quickly in order not to
 * hinder the handling of itself or other interrupts. SoftIRQ allows the top-half to trigger a
 * bottom-half, which runs in thread context with interrupts enabled, and asynchronously performs
 * more complicated and time consuming work in a context that will not affect interrupt latency.
 **************************************************************************************************/
#ifndef HC75E97E9_3A69_49B9_99F6_4CC95C61EF52
#define HC75E97E9_3A69_49B9_99F6_4CC95C61EF52

#include <stddef.h>
#include <stdbool.h>

/*
 * Takes advantage of atomic types since C11 so that we don't have to disable interrupts
 */
#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
#	include <stdatomic.h>
#endif



/*
 * SoftIRQ Status
 * ALL MEMBERS ARE PRIVATE.
 */
struct softirq_status
{
#if (__STDC_VERSION__ >= 201112L) && (!__STDC_NO_ATOMICS__)
	/*
	 * Only lock-free atomic types can be safely shared with interrupts enabled.
	 * The atomic_flag type is always lock-free.
	 */
	volatile atomic_flag is_inactive;

#else
	volatile bool is_inactive;
#endif
};



/*
 * SoftIRQ Entity
 * ALL MEMBERS ARE PRIVATE.
 */
struct softirq_inst
{
	/*
	 * SoftIRQ per-vector statuses
	 * RW ARRAY ELEMENTS NEED SYNCHRONIZATION.
	 */
	struct softirq_status *vec_status;

	/* SoftIRQ per-vector actions */
	void (*const *vec_action)(void);

	/* number of SoftIRQ vectors */
	size_t num_vec;
};



#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Initializes a SoftIRQ instance
 */
void softirq_init(struct softirq_inst *inst, struct softirq_status *vec_status,
		void (*const *vec_action)(void), size_t num_vec);


/*
 * Pends a SoftIRQ vector
 */
void softirq_pend(struct softirq_inst *inst, size_t irq);


/*
 * Services the highest priority pending SoftIRQ
 */
void softirq_serve_one(struct softirq_inst *inst);


#if defined(__cplusplus)
}
#endif


#endif /* HC75E97E9_3A69_49B9_99F6_4CC95C61EF52 */
