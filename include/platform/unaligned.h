/***************************************************************************************************
 * Unaligned Integer Access Functions
 *
 * Directly casting between pointer-to-integer types is implementation-defined behavior and can
 * cause memory-access problems if the pointer is not aligned to the boundary of the integer type.
 *
 * Provides routines to load or store integer types into byte sequences, which may be unaligned.
 * The byte sequences are in platform native endianness.
 **************************************************************************************************/
#ifndef H8552EF09_EFE3_4358_9B48_E2CFC32E5B41
#define H8552EF09_EFE3_4358_9B48_E2CFC32E5B41

#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif


#if defined(UINT16_MAX)
uint16_t align_u16(const void *data);
void unalign_u16(uint16_t val, void *data);
#endif /* UINT16_MAX */



#if defined(UINT32_MAX)
uint32_t align_u32(const void *data);
void unalign_u32(uint32_t val, void *data);
#endif /* UINT32_MAX */



#if defined(UINT64_MAX)
uint64_t align_u64(const void *data);
void unalign_u64(uint64_t val, void *data);
#endif /* UINT64_MAX */



#if defined(__cplusplus)
}
#endif

#endif /* H8552EF09_EFE3_4358_9B48_E2CFC32E5B41 */

