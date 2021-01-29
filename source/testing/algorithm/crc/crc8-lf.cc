/*
 * CRC8 LSb-first unit tests
 */
#include <googletest/gtest.h>

#include <algorithm/crc.h>
#include <algorithm/private/crc-info.h>
#include <testing/death-string.h>



TEST(CRC8LF, DeathTest)
{
	struct crc8_lf_inst dummy_inst;
	struct crc8_lf_info dummy_info;

#if CONFIG_CRC_TABLE
	dummy_info.table = nullptr;
#endif

	EXPECT_DEATH(crc8_lf_begin(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(crc8_lf_begin(&dummy_inst, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(crc8_lf_begin(nullptr, &dummy_info), TESTING_DEATH_STRING);

	crc8_lf_begin(&dummy_inst, &dummy_info);

	EXPECT_DEATH(crc8_lf_update(nullptr, nullptr, 0), TESTING_DEATH_STRING);
	EXPECT_DEATH(crc8_lf_update(&dummy_inst, nullptr, 1), TESTING_DEATH_STRING);
	EXPECT_DEATH(crc8_lf_update(nullptr, &dummy_info, 0), TESTING_DEATH_STRING);

	EXPECT_DEATH(crc8_lf_finish(nullptr), TESTING_DEATH_STRING);
}
