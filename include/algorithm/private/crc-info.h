/***************************************************************************************************
 * Cyclic Redundancy Check
 * Private Header: Variant Parametric Block
 *
 * Include this header to access an variant parametric block.
 **************************************************************************************************/
#ifndef H3311F603_189B_4D63_966A_48E50F11D7FD
#define H3311F603_189B_4D63_966A_48E50F11D7FD

#include <stdint.h>



#if CONFIG_CRC_TABLE
struct crc32_mf_info
{
	uint32_t init;
	uint32_t xor_out;
	const uint32_t *table;
};

struct crc16_mf_info
{
	uint16_t init;
	uint16_t xor_out;
	const uint16_t *table;
};

struct crc8_mf_info
{
	uint8_t init;
	uint8_t xor_out;
	const uint8_t *table;
};

struct crc32_lf_info
{
	uint32_t init;
	uint32_t xor_out;
	const uint32_t *table;
};

struct crc16_lf_info
{
	uint16_t init;
	uint16_t xor_out;
	const uint16_t *table;
};

struct crc8_lf_info
{
	uint8_t init;
	uint8_t xor_out;
	const uint8_t *table;
};



#else /* !CONFIG_CRC_TABLE */
struct crc32_mf_info
{
	uint32_t init;
	uint32_t xor_out;
	uint32_t divisor;
};

struct crc16_mf_info
{
	uint16_t init;
	uint16_t xor_out;
	uint16_t divisor;
};

struct crc8_mf_info
{
	uint8_t init;
	uint8_t xor_out;
	uint8_t divisor;
};

struct crc32_lf_info
{
	uint32_t init;
	uint32_t xor_out;
	uint32_t divisor;
};

struct crc16_lf_info
{
	uint16_t init;
	uint16_t xor_out;
	uint16_t divisor;
};

struct crc8_lf_info
{
	uint8_t init;
	uint8_t xor_out;
	uint8_t divisor;
};
#endif /* CONFIG_CRC_TABLE */

#endif /* H3311F603_189B_4D63_966A_48E50F11D7FD */
