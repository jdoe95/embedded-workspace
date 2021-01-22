/***************************************************************************************************
 * Uniprocessing Critical Sections
 *
 * This header provides routines to synchronize access to data shared between interrupt and thread
 * context so that the shared data is always in a consistent state. If the CPU hardware has features
 * that interferes with synchronization, such as caching or instruction reordering, the
 * corresponding platform dependent mechanisms will be invoked to ensure proper operation.
 **************************************************************************************************/
#ifndef H52671A94_C940_45D9_A9D2_4005B5D8C840
#define H52671A94_C940_45D9_A9D2_4005B5D8C840

#include <stdbool.h>



/*
 * CPU interrupt state
 * ALL MEMBERS ARE PUBLIC.
 */
struct irq_state
{
	bool is_enabled;   /* set if CPU allows interrupts */
};



#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Enters and exits a critical section while allowing critical section nesting
 * The function pair does the following
 *
 *  1. Disables CPU interrupts or restores previously-saved CPU interrupt enabling state.
 *
 *  2. Forces completion of cached read/writes. Memory load/stores appearing in program order before
 *     the barrier are observed before those appearing after the barrier. This ensures shared data
 *     consistency is observed from within the critical section, and that inconsistencies in the
 *     critical section are not observed by programs external to the critical section.
 *
 *  3. Forbids the CPU from reordering instructions in program order from after the barrier to
 *     before the barrier. This prevents executing instructions in the critical section before the
 *     critical section is entered, or deferring instructions to outside the critical section.
 */
void irq_save_and_barrier(struct irq_state *state);
void irq_restore_and_barrier(const struct irq_state *irq_state);

#if defined(__cplusplus)
}
#endif

#endif /* H52671A94_C940_45D9_A9D2_4005B5D8C840 */
