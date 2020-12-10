/***************************************************************************************************
 * Byte Swapping Functions
 *
 * If this module finds a way to optimize byte swapping on the target platform, it will use that.
 * Otherwise, a default implementation is provided.
 **************************************************************************************************/
#include <platform/byteswap.h>
#include <platform/endian.h>



#if CONFIG_ENDIANNESS == ENDIAN_BIG

#	if defined(UINT16_MAX)
uint16_t byteswap_from_u16le(uint16_t val)
{
	return byteswap_u16(val);
}

uint16_t byteswap_from_u16be(uint16_t val)
{
	return val;
}

uint16_t byteswap_to_u16le(uint16_t val)
{
	return byteswap_u16(val);
}

uint16_t byteswap_to_u16be(uint16_t val)
{
	return val;
}
#	endif



#	if defined(UINT32_MAX)
uint32_t byteswap_from_u32le(uint32_t val)
{
	return byteswap_u32(val);
}

uint32_t byteswap_from_u32be(uint32_t val)
{
	return val;
}

uint32_t byteswap_to_u32le(uint32_t val)
{
	return byteswap_u32(val);
}

uint32_t byteswap_to_u32be(uint32_t val)
{
	return val;
}
#	endif



#	if defined(UINT64_MAX)
uint64_t byteswap_from_u64le(uint64_t val)
{
	return byteswap_u64(val);
}

uint64_t byteswap_from_u64be(uint64_t val)
{
	return val;
}

uint64_t byteswap_to_u64le(uint64_t val)
{
	return byteswap_u64(val);
}

uint64_t byteswap_to_u64be(uint64_t val)
{
	return val;
}
#	endif



#elif CONFIG_ENDIANNESS == ENDIAN_LITTLE

#	if defined(UINT16_MAX)
uint16_t byteswap_from_u16le(uint16_t val)
{
	return val;
}

uint16_t byteswap_from_u16be(uint16_t val)
{
	return byteswap_u16(val);
}

uint16_t byteswap_to_u16le(uint16_t val)
{
	return val;
}

uint16_t byteswap_to_u16be(uint16_t val)
{
	return byteswap_u16(val);
}
#	endif



#	if defined(UINT32_MAX)
uint32_t byteswap_from_u32le(uint32_t val)
{
	return val;
}

uint32_t byteswap_from_u32be(uint32_t val)
{
	return byteswap_u32(val);
}

uint32_t byteswap_to_u32le(uint32_t val)
{
	return val;
}

uint32_t byteswap_to_u32be(uint32_t val)
{
	return byteswap_u32(val);
}
#	endif



#	if defined(UINT64_MAX)
uint64_t byteswap_from_u64le(uint64_t val)
{
	return val;
}

uint64_t byteswap_from_u64be(uint64_t val)
{
	return byteswap_u64(val);
}

uint64_t byteswap_to_u64le(uint64_t val)
{
	return val;
}

uint64_t byteswap_to_u64be(uint64_t val)
{
	return byteswap_u64(val);
}
#	endif



#else
#	error Unsupported endianness.
#endif

