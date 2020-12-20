/*
 * Unaligned Unit Tests
 */
#include <googletest/gmock.h>

#include <platform/unaligned.h>
#include <testing/death-string.h>
#include <platform/endian.h>


#if defined(UINT16_MAX)
TEST(Unaligned, U16DeathTest)
{
	EXPECT_DEATH(align_u16(nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(unalign_u16(static_cast<uint16_t>(0), nullptr), TESTING_DEATH_STRING);
}

TEST(Unaligned, AlignU16)
{
	uint8_t data[2] = {0xAA, 0xBB};

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_EQ(align_u16(data), static_cast<uint16_t>(0xAABB));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_EQ(align_u16(data), static_cast<uint16_t>(0xBBAA));

#	else
#		error Unimplemented.
#	endif
}

TEST(Unaligned, UnalignU16)
{
	uint8_t data[2] = {0};

	unalign_u16(static_cast<uint16_t>(0xAABB), data);

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_THAT(data, testing::ElementsAre(0xAA, 0xBB));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_THAT(data, testing::ElementsAre(0xBB, 0xAA));

#	else
#		error Unimplemented.
#	endif
}
#endif



#if defined(UINT32_MAX)
TEST(Unaligned, U32DeathTest)
{
	EXPECT_DEATH(align_u32(nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(unalign_u32(static_cast<uint32_t>(0), nullptr), TESTING_DEATH_STRING);
}

TEST(Unaligned, AlignU32)
{
	uint8_t data[4] = {0xAA, 0xBB, 0xCC, 0xDD};

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_EQ(align_u32(data), static_cast<uint32_t>(0xAABBCCDD));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_EQ(align_u32(data), static_cast<uint32_t>(0xDDCCBBAA));

#	else
#		error Unimplemented.
#	endif
}

TEST(Unaligned, UnalignU32)
{
	uint8_t data[4] = {0};

	unalign_u32(static_cast<uint32_t>(0xAABBCCDD), data);

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_THAT(data, testing::ElementsAre(0xAA, 0xBB, 0xCC, 0xDD));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_THAT(data, testing::ElementsAre(0xDD, 0xCC, 0xBB, 0xAA));

#	else
#		error Unimplemented.
#	endif
}
#endif



#if defined(UINT64_MAX)
TEST(Unaligned, U64DeathTest)
{
	EXPECT_DEATH(align_u64(nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(unalign_u64(static_cast<uint64_t>(0), nullptr), TESTING_DEATH_STRING);
}

TEST(Unaligned, AlignU64)
{
	uint8_t data[8] = {0xAA, 0xBB, 0xCC, 0xDD, 0x11, 0x22, 0x33, 0x44};

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_EQ(align_u64(data), static_cast<uint64_t>(0xAABBCCDD11223344));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_EQ(align_u64(data), static_cast<uint64_t>(0x44332211DDCCBBAA));

#	else
#		error Unimplemented.
#	endif
}

TEST(Unaligned, UnalignU64)
{
	uint8_t data[8] = {0};

	unalign_u64(static_cast<uint64_t>(0xAABBCCDD11223344), data);

#	if CONFIG_ENDIAN == ENDIAN_BIG
	EXPECT_THAT(data, testing::ElementsAre(0xAA, 0xBB, 0xCC, 0xDD, 0x11, 0x22, 0x33, 0x44));

#	elif CONFIG_ENDIAN == ENDIAN_LITTLE
	EXPECT_THAT(data, testing::ElementsAre(0x44, 0x33, 0x22, 0x11, 0xDD, 0xCC, 0xBB, 0xAA));

#	else
#		error Unimplemented.
#	endif
}
#endif
