/***************************************************************************************************
 * Secure Hash Algorithm 256
 * This is an implementation of one of the algorithms provided in Secure Hash Standard (SHS) [1].
 *
 * Bibliography
 * [1] Federal Information Processing Standards Publication. Secure Hash Standard (SHS).
 *     FIPS PUB 180-4. Information Technology Laboratory. Gaithersburg, MD 20899-8900:
 *     National Institute of Standards and Technology, August 2015.
 **************************************************************************************************/
#ifndef H28644775_C82A_4725_AA02_3E36FA60AE2B
#define H28644775_C82A_4725_AA02_3E36FA60AE2B

#include <stdint.h>
#include <stddef.h>

/*
 * Use this to define an uint8_t array to hold a SHA256 digest
 */
#define SHA256_DIGEST_SIZE   (32)



/*
 * SHA256 state data
 */
struct sha256
{
	/* intermediate and final hash values */
	uint32_t hash[8];

	/* chunk data */
	uint8_t chunk[64];

	/* message schedule */
	uint32_t w[64];

	/* working variables */
	uint32_t a;
	uint32_t b;
	uint32_t c;
	uint32_t d;
	uint32_t e;
	uint32_t f;
	uint32_t g;
	uint32_t h;

	/* filled chunk length in bytes */
	size_t len_filled;

	/* accumulated message length in bytes */
	size_t len_total;
};


#ifdef __cplusplus
extern "C" {
#endif



/* prepare for SHA-256 calculation */
void sha256_begin(struct sha256 *inst);

/* feed data into the SHA-256 calculator */
void sha256_update(struct sha256 *inst, const void *data, size_t len);

/* finish calculation and copy result */
void sha256_finish(struct sha256 *inst, void *digest);



#ifdef __cplusplus
}
#endif

#endif /* H28644775_C82A_4725_AA02_3E36FA60AE2B */

