/***************************************************************************************************
 * Byte Swapping Functions
 *
 * If this module finds a way to optimize byte swapping on the target platform, it will use that.
 * Otherwise, a default implementation is provided.
 **************************************************************************************************/
#ifndef H2AB9C900_525F_4952_95BC_F5EC83F87FA3
#define H2AB9C900_525F_4952_95BC_F5EC83F87FA3

#include <stdint.h>



#if defined(__cplusplus)
extern "C" {
#endif



#if defined(UINT16_MAX)
/* swaps high and low bytes for uint16_t */
uint16_t byteswap_u16(uint16_t data);

/* swaps little endian into platform endianness */
uint16_t byteswap_from_u16le(uint16_t val);

/* swaps big endian into platform endianness */
uint16_t byteswap_from_u16be(uint16_t val);

/* swaps platform endianness into little endian */
uint16_t byteswap_to_u16le(uint16_t val);

/* swaps platform endianness into big endian */
uint16_t byteswap_to_u16be(uint16_t val);
#endif /* UINT16_MAX */



#if defined(UINT32_MAX)
/* swaps high and low bytes for uint32_t */
uint32_t byteswap_u32(uint32_t data);

/* swaps little endian into platform endianness */
uint32_t byteswap_from_u32le(uint32_t val);

/* swaps big endian into platform endianness */
uint32_t byteswap_from_u32be(uint32_t val);

/* swaps platform endianness into little endian */
uint32_t byteswap_to_u32le(uint32_t val);

/* swaps platform endianness into big endian */
uint32_t byteswap_to_u32be(uint32_t val);
#endif /* UINT32_MAX */



#if defined(UINT64_MAX)
/* swaps high and low bytes for uint64_t */
uint64_t byteswap_u64(uint64_t data);

/* swaps little endian into platform endianness */
uint64_t byteswap_from_u64le(uint64_t val);

/* swaps big endian into platform endianness */
uint64_t byteswap_from_u64be(uint64_t val);

/* swaps platform endianness into little endian */
uint64_t byteswap_to_u64le(uint64_t val);

/* swaps platform endianness into big endian */
uint64_t byteswap_to_u64be(uint64_t val);
#endif /* UINT64_MAX */



#if defined(__cplusplus)
}
#endif

#endif /* H2AB9C900_525F_4952_95BC_F5EC83F87FA3 */

