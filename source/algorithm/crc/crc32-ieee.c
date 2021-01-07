/*
 * Cyclic Redundancy Check
 * CRC32_IEEE Variant parametric block
 */
#include <algorithm/crc.h>
#include <algorithm/private/crc-info.h>
#include <algorithm/private/crc-table.h>



/*
 * External Symbols
 */
#if CONFIG_CRC_TABLE
const struct crc32_lf_info CRC32_IEEE =
{
	.init = (uint32_t) 0xFFFFFFFF,
	.xor_out = (uint32_t) 0xFFFFFFFF,
	.table = CRC32_TABLE_IEEE
};



#else /* !CONFIG_CRC_TABLE */
const struct crc32_lf_info CRC32_IEEE =
{
	.init = (uint32_t) 0xFFFFFFFF,
	.xor_out = (uint32_t) 0xFFFFFFFF,
	.divisor = (uint32_t) 0xEDB88320
};
#endif /* CONFIG_CRC_TABLE */

