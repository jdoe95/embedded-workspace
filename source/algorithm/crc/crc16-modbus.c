/*
 * Cyclic Redundancy Check
 * CRC16_MODBUS Variant parametric block
 */
#include <algorithm/crc.h>
#include <algorithm/private/crc-info.h>
#include <algorithm/private/crc-table.h>



/*
 * External Symbols
 */
#if CONFIG_CRC_TABLE
const struct crc16_lf_info CRC16_MODBUS =
{
	.init = (uint16_t) 0xFFFF,
	.xor_out = (uint16_t) 0x0000,
	.table = CRC16_TABLE_MODBUS
};



#else /* !CONFIG_CRC_TABLE */
const struct crc16_lf_info CRC16_MODBUS =
{
	.init = (uint16_t) 0xFFFF,
	.xor_out = (uint16_t) 0x0000,
	.divisor = (uint16_t) 0xA001
};
#endif /* CONFIG_CRC_TABLE */
