/***************************************************************************************************
 * Thread and Interrupt Safe Memory Filling Routines
 *
 * This module provides thread and interrupt safe equivalents to replace the unsafe ones in the
 * standard library. memccpy(), memchr(), memcmp(), memmove(), memset(), etc are only async-signal
 * safe after POSIX.1-2016. It is often impossible to know which POSIX version the standard library
 * is implementing, so it is wise to avoid them altogether.
 *
 * Async-signal (AS) is a type of software interrupt on UNIX. For a stdlib function to be interrupt
 * safe in baremetal environments, it needs to be MT-safe and AS-safe and AC-safe.
 *
 * See `man attributes.7` and `man signal-safety.7`
 **************************************************************************************************/
#ifndef HBB3B50CB_4408_4CD0_BCF3_E4F5018F8ADC
#define HBB3B50CB_4408_4CD0_BCF3_E4F5018F8ADC

#include <stddef.h>



#if defined(__cplusplus)
extern "C" {
#endif

/*
 * A fancier replacement for memset()
 * Pad the remaining bytes of memory pointed by 'buf' with zero, starting at an offset
 */
void mem_zeropad(void *buf, size_t buf_size, size_t start);


/*
 * A fancier replacement for memcpy()
 */
void mem_copy(void *to, size_t to_start, const void *from, size_t from_start, size_t size);


#if defined(__cplusplus)
}
#endif

#endif /* HBB3B50CB_4408_4CD0_BCF3_E4F5018F8ADC */
