/*
 * CRC32-IEEE Unit Tests
 */
#include <googletest/gtest.h>

#include <algorithm/crc.h>



TEST(CRC32_IEEE, String1)
{
	struct crc32_lf_inst inst;

	crc32_lf_begin(&inst, &CRC32_IEEE);
	crc32_lf_update(&inst, "123456789", 9);
	uint32_t result = crc32_lf_finish(&inst);

	EXPECT_EQ(result, static_cast<uint32_t>(0xCBF43926));
}


TEST(CRC32_IEEE, String2)
{
	struct crc32_lf_inst inst;

	crc32_lf_begin(&inst, &CRC32_IEEE);
	crc32_lf_update(&inst, "123456789", 9);
	crc32_lf_update(&inst, "123456789", 9);
	uint32_t result = crc32_lf_finish(&inst);

	EXPECT_EQ(result, static_cast<uint32_t>(0x4B837AE4));
}

