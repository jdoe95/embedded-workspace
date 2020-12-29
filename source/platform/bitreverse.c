/***************************************************************************************************
 * Bit Reversal Functions
 *
 * If this module finds a way to optimize bit swapping on the target platform, it will use that.
 * Otherwise, a default implementation is provided.
 **************************************************************************************************/

#include <platform/bitreverse.h>
#include <platform/contend.h>



#if defined(UINT8_MAX)
uint8_t bitreverse_u8(uint8_t data)
{
	data = (data & (uint8_t) 0xF0) >> 4 | (data & (uint8_t) 0x0F) << 4;
	data = (data & (uint8_t) 0xCC) >> 2 | (data & (uint8_t) 0x33) << 2;
	data = (data & (uint8_t) 0xAA) >> 1 | (data & (uint8_t) 0x55) << 1;

	return data;
}
#endif



#if defined(UINT16_MAX)
uint16_t bitreverse_u16(uint16_t data)
{
	data = (data & (uint16_t) 0xFF00) >> 8 | (data & (uint16_t) 0x00FF) << 8;
	data = (data & (uint16_t) 0xF0F0) >> 4 | (data & (uint16_t) 0x0F0F) << 4;
	data = (data & (uint16_t) 0xCCCC) >> 2 | (data & (uint16_t) 0x3333) << 2;
	data = (data & (uint16_t) 0xAAAA) >> 1 | (data & (uint16_t) 0x5555) << 1;

	return data;
}
#endif



#if defined(UINT32_MAX)
uint32_t bitreverse_u32(uint32_t data)
{
	data = (data & (uint32_t) 0xFFFF0000) >> 16 | (data & (uint32_t) 0x0000FFFF) << 16;
	data = (data & (uint32_t) 0xFF00FF00) >> 8 | (data & (uint32_t) 0x00FF00FF) << 8;
	data = (data & (uint32_t) 0xF0F0F0F0) >> 4 | (data & (uint32_t) 0x0F0F0F0F) << 4;
	data = (data & (uint32_t) 0xCCCCCCCC) >> 2 | (data & (uint32_t) 0x33333333) << 2;
	data = (data & (uint32_t) 0xAAAAAAAA) >> 1 | (data & (uint32_t) 0x55555555) << 1;

	return data;
}
#endif



#if defined(UINT64_MAX)
uint64_t bitreverse_u64(uint64_t data)
{
	data = (data & (uint64_t) 0xFFFFFFFF00000000) >> 32 |
		(data & (uint64_t) 0x00000000FFFFFFFF) << 32;

	data = (data & (uint64_t) 0xFFFF0000FFFF0000) >> 16 |
		(data & (uint64_t) 0x0000FFFF0000FFFF) << 16;

	data = (data & (uint64_t) 0xFF00FF00FF00FF00) >> 8 |
		(data & (uint64_t) 0x00FF00FF00FF00FF) << 8;

	data = (data & (uint64_t) 0xF0F0F0F0F0F0F0F0) >> 4 |
		(data & (uint64_t) 0x0F0F0F0F0F0F0F0F) << 4;

	data = (data & (uint64_t) 0xCCCCCCCCCCCCCCCC) >> 2 |
		(data & (uint64_t) 0x3333333333333333) << 2;

	data = (data & (uint64_t) 0xAAAAAAAAAAAAAAAA) >> 1 |
		(data & (uint64_t) 0x5555555555555555) << 1;

	return data;
}
#endif

