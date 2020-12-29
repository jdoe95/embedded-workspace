/***************************************************************************************************
 * Bit Reversal Functions
 *
 * If this module finds a way to optimize bit swapping on the target platform, it will use that.
 * Otherwise, a default implementation is provided.
 **************************************************************************************************/
#ifndef HF43650E1_6C53_4B51_8B26_4C0443F4D0D7
#define HF43650E1_6C53_4B51_8B26_4C0443F4D0D7

#include <stdint.h>
#include <stddef.h>



#if defined(__cplusplus)
extern "C" {
#endif


#if defined(UINT8_MAX)
uint8_t bitreverse_u8(uint8_t data);
#endif



#if defined(UINT16_MAX)
uint16_t bitreverse_u16(uint16_t data);
#endif


#if defined(UINT32_MAX)
uint32_t bitreverse_u32(uint32_t data);
#endif



#if defined(UINT64_MAX)
uint64_t bitreverse_u64(uint64_t data);
#endif



#if defined(__cplusplus)
}
#endif


#endif /* HF43650E1_6C53_4B51_8B26_4C0443F4D0D7 */
