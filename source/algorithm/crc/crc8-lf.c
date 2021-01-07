/*
 * Cyclic Redundancy Check
 * 8-bit LSb-first Variant
 */
#include <algorithm/crc.h>
#include <algorithm/private/crc-info.h>
#include <platform/contend.h>



/*
 * External Symbols
 */

void crc8_lf_begin(struct crc8_lf_inst* inst, const struct crc8_lf_info *info)
{
	CONTEND(inst != NULL);
	CONTEND(info != NULL);

	inst->info = info;
	inst->remainder = info->init;
}



uint8_t crc8_lf_finish(struct crc8_lf_inst *inst)
{
	CONTEND(inst != NULL);

	CONTEND(inst->info != NULL);

	return inst->remainder ^ inst->info->xor_out;
}



void crc8_lf_update(struct crc8_lf_inst *inst, const void *data, size_t len)
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
		uint8_t dividend;

#if CONFIG_CRC_TABLE

		/* extract dividend slice containing 8 data terms and remainder from previous slice */
		uint8_t lookup_key = (uint8_t) inst->remainder ^ data_byte[byte_index];
		dividend = (uint8_t) 0;

		/*
		 * Euclidian division, use the divisor to cancel out 8 highest order terms in the dividend.
		 * Instead of processing the 8 terms one by one, look up the combined subtrahend of the 8
		 * terms from a table.
		 */
		/* subtract subtrahend from the dividend */
		dividend ^= inst->info->table[lookup_key];


#else /* !CONFIG_CRC_TABLE */
		/* extract dividend slice containing 8 data terms and remainder from previous slice */
		dividend = inst->remainder ^ (uint8_t) data_byte[byte_index];

		/*
		 * Euclidian division, use the divisor to cancel out 8 highest order terms in the dividend.
		 */
		for (size_t counter = 0; counter < 8; ++counter)
		{
			/* dividend has a term here */
			if (dividend & (uint8_t) 0x01)

				/* subtract divisor from dividend and move to the next dividend term */
				dividend = (uint8_t) (dividend >> 1) ^ inst->info->divisor;

			/* dividend term is already zero */
			else
				/* do not subtract, move to next term directly */
				dividend >>= 1;
		}

#endif /* CONFIG_CRC_TABLE */

		/* after the Euclidian division, the variable contains the remainder */
		inst->remainder = dividend;
	}
}
