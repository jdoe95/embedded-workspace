/***************************************************************************************************
 * Synchronization lock functions
 * Creates a critical section for non-atomic concurrent access
 **************************************************************************************************/
#ifndef H71428154_E1C6_4012_9D80_27B957290189
#define H71428154_E1C6_4012_9D80_27B957290189



/*
 * For Symmetric Multiprocessing Platforms
 */
#if defined(CONFIG_SMP)
#	error Not implemented.



/*
 * Uniprocessing platforms mask IRQs to create critical sections.
 */
#else
#	define SPINLOCK_DECL(DECL_NAME)            /* intentionally left blank */
#	define SPINLOCK_IRQ_SAVE(LOCK_PTR)         irq_save()
#	define SPINUNLOCK_IRQ_RESTORE(LOCK_PTR)    irq_restore()
#endif



#if defined(__cplusplus)
extern "C" {
#endif


/* Disables all CPU interrupts. */
void irq_save(void);

/* Enables all CPU interrupts. */
void irq_restore(void);


#if defined(__cplusplus)
}
#endif

#endif /* H71428154_E1C6_4012_9D80_27B957290189 */
