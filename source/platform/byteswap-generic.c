/***************************************************************************************************
 * Byte Swapping Functions
 *
 * If this module finds a way to optimize byte swapping on the target platform, it will use that.
 * Otherwise, a default implementation is provided.
 **************************************************************************************************/
#include <platform/byteswap.h>



/*
 * GCC __builtin can take advantage of special platform instructions, so prefer builtins if detected
 * using GCC.
 */
#if defined(__GNUC__)

#	if defined(UINT16_MAX)
uint16_t byteswap_u16(uint16_t data)
{
	return __builtin_bswap16(data);
}
#	endif /* UINT16_MAX */


#	if defined(UINT32_MAX)
uint32_t byteswap_u32(uint32_t data)
{
	return __builtin_bswap32(data);
}
#	endif /* UINT32_MAX */


#	if defined(UINT64_MAX)
uint64_t byteswap_u64(uint64_t data)
{
	return __builtin_bswap64(data);
}
#	endif /* UINT64_MAX */



/* not using a known compiler, so falls back to universal implementation */
#else

#	if defined(UINT16_MAX)
uint16_t byteswap_u16(uint16_t data)
{
	return (data >> 8) | (data << 8);
}
#	endif /* UINT16_MAX */


#	if defined(UINT32_MAX)
uint32_t byteswap_u32(uint32_t data)
{
	return ((data & (uint32_t) 0x000000ff) >> 24) |
		((data & (uint32_t) 0x0000ff00) >>  8) |
		((data & (uint32_t) 0x00ff0000) <<  8) |
		((data & (uint32_t) 0xff000000) << 24);
}
#	endif /* UINT32_MAX */


#	if defined(UINT64_MAX)
uint64_t byteswap_u64(uint64_t data)
{
	return ((data & (uint64_t) 0x00000000000000ff) << 56) |
		((data & (uint64_t) 0x000000000000ff00) << 40) |
		((data & (uint64_t) 0x0000000000ff0000) << 24) |
		((data & (uint64_t) 0x00000000ff000000) <<  8) |
		((data & (uint64_t) 0x000000ff00000000) >>  8) |
		((data & (uint64_t) 0x0000ff0000000000) >> 24) |
		((data & (uint64_t) 0x00ff000000000000) >> 40) |
		((data & (uint64_t) 0xff00000000000000) >> 56);
}
#	endif /* UINT64_MAX */



#endif /* defined(__GNUC__) */
