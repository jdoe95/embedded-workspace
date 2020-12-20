/*
 * Byteswap Unit Tests
 */
#include <googletest/gtest.h>

#include <platform/byteswap.h>
#include <platform/endian.h>



#if defined(UINT16_MAX)
TEST(Byteswap, U16)
{
	EXPECT_EQ(byteswap_u16((uint16_t)0xAABB), (uint16_t)0xBBAA);
}

TEST(Byteswap, FromU16LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u16le((uint16_t)0xCCDD), (uint16_t)0xCCDD);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u16le((uint16_t)0xCCDD), (uint16_t)0xDDCC);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, FromU16BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u16be((uint16_t)0xCCDD), (uint16_t)0xDDCC);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u16be((uint16_t)0xCCDD), (uint16_t)0xCCDD);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU16LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u16le((uint16_t)0xCCDD), (uint16_t)0xCCDD);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u16le((uint16_t)0xCCDD), (uint16_t)0xDDCC);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU16BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u16be((uint16_t)0xCCDD), (uint16_t)0xDDCC);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u16be((uint16_t)0xCCDD), (uint16_t)0xCCDD);

#else
#	error Unimplemented.
#endif
}
#endif



#if defined(UINT32_MAX)
TEST(Byteswap, U32)
{
	EXPECT_EQ(byteswap_u32((uint32_t)0xAABBCCDD), (uint32_t)0xDDCCBBAA);
}

TEST(Byteswap, FromU32LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u32le((uint32_t)0x11223344), (uint32_t)0x11223344);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u32le((uint32_t)0x11223344), (uint32_t)0x44332211);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, FromU32BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u32be((uint32_t)0x11223344), (uint32_t)0x44332211);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u32be((uint32_t)0x11223344), (uint32_t)0x11223344);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU32LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u32le((uint32_t)0x11223344), (uint32_t)0x11223344);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u32le((uint32_t)0x11223344), (uint32_t)0x44332211);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU32BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u32be((uint32_t)0x11223344), (uint32_t)0x44332211);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u32be((uint32_t)0x11223344), (uint32_t)0x11223344);

#else
#	error Unimplemented.
#endif
}
#endif



#if defined(UINT64_MAX)
TEST(Byteswap, U64)
{
	EXPECT_EQ(byteswap_u64((uint64_t)0x1122334455667788), (uint64_t)0x8877665544332211);
}

TEST(Byteswap, FromU64LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u64le((uint64_t)0x1122334455667788), (uint64_t)0x1122334455667788);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u64le((uint64_t)0x1122334455667788), (uint64_t)0x8877665544332211);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, FromU64BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_from_u64be((uint64_t)0x1122334455667788), (uint64_t)0x8877665544332211);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_from_u64be((uint64_t)0x1122334455667788), (uint64_t)0x1122334455667788);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU64LE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u64le((uint64_t)0x1122334455667788), (uint64_t)0x1122334455667788);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u64le((uint64_t)0x1122334455667788), (uint64_t)0x8877665544332211);

#else
#	error Unimplemented.
#endif
}

TEST(Byteswap, ToU64BE)
{
#if CONFIG_ENDIANNESS == ENDIAN_LITTLE
	EXPECT_EQ(byteswap_to_u64be((uint64_t)0x1122334455667788), (uint64_t)0x8877665544332211);

#elif CONFIG_ENDIANNESS == ENDIAN_BIG
	EXPECT_EQ(byteswap_to_u64be((uint64_t)0x1122334455667788), (uint64_t)0x1122334455667788);

#else
#	error Unimplemented.
#endif
}
#endif

