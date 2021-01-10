/*
 * CRC32-IEEE Unit Tests
 */
#include <googletest/gtest.h>

#include <algorithm/crc.h>



TEST(CRC16_MODBUS, String1)
{
	struct crc16_lf inst;

	crc16_lf_begin(&inst, &CRC16_MODBUS);
	crc16_lf_update(&inst, "123456789", 9);
	uint16_t result = crc16_lf_finish(&inst);

	EXPECT_EQ(result, (uint16_t) 0x4B37);
}



TEST(CRC16_MODBUS, String2)
{
	struct crc16_lf inst;

	crc16_lf_begin(&inst, &CRC16_MODBUS);
	crc16_lf_update(&inst, "123456789", 9);
	crc16_lf_update(&inst, "123456789", 9);
	uint16_t result = crc16_lf_finish(&inst);

	EXPECT_EQ(result, (uint16_t) 0x090A);
}

