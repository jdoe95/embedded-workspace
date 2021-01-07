/*
 * Cyclic Redundancy Check
 * 32-bit MSb-first Variant
 */
#include <algorithm/crc.h>
#include <algorithm/private/crc-info.h>
#include <platform/contend.h>



/*
 * External Symbols
 */

void crc32_mf_begin(struct crc32_mf* inst, const struct crc32_mf_info *info)
{
	CONTEND(inst != NULL);
	CONTEND(info != NULL);

	inst->info = info;
	inst->remainder = info->init;
}



uint32_t crc32_mf_finish(struct crc32_mf *inst)
{
	CONTEND(inst != NULL);

	CONTEND(inst->info != NULL);

	return inst->remainder ^ inst->info->xor_out;
}



void crc32_mf_update(struct crc32_mf *inst, const void *data, size_t len)
{
	CONTEND(inst != NULL);
	CONTEND((data != NULL) || (len == 0));

	CONTEND(inst->info != NULL);

#if CONFIG_CRC_TABLE
	CONTEND(inst->info->table != NULL);
#endif

	for (size_t byte_index = (size_t) 0; byte_index < len; ++byte_index)
	{
		const uint8_t *data_byte = (const uint8_t*) data;
		uint32_t dividend;

#if CONFIG_CRC_TABLE

		/* extract dividend slice containing 8 data terms and remainder from previous slice */
		uint8_t lookup_key = (uint8_t) (inst->remainder >> 24) ^ data_byte[byte_index];
		dividend = inst->remainder << 8;

		/*
		 * Euclidian division, use the divisor to cancel out 8 highest order terms in the dividend.
		 * Instead of processing the 8 terms one by one, look up the combined subtrahend of the 8
		 * terms from a table.
		 */
		/* subtract subtrahend from the dividend */
		dividend ^= inst->info->table[lookup_key];


#else /* !CONFIG_CRC_TABLE */
		/* extract dividend slice containing 8 data terms and remainder from previous slice */
		dividend = inst->remainder ^ ((uint32_t) data_byte[byte_index] << 24);

		/*
		 * Euclidian division, use the divisor to cancel out 8 highest order terms in the dividend.
		 */
		for (size_t counter = 0; counter < 8; ++counter)
		{
			/* dividend has a term here */
			if (dividend & (uint32_t) 0x80000000)

				/* subtract divisor from dividend and move to the next dividend term */
				dividend = (uint32_t) (dividend << 1) ^ inst->info->divisor;

			/* dividend term is already zero */
			else
				/* do not subtract, move to next term directly */
				dividend <<= 1;
		}

#endif /* CONFIG_CRC_TABLE */

		/* after the Euclidian division, the variable contains the remainder */
		inst->remainder = dividend;
	}
}
