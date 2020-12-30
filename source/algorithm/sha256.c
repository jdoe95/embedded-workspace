/***************************************************************************************************
 * Secure Hash Algorithm 256
 * This is an implementation of one of the algorithms provided in Secure Hash Standard (SHS) [1].
 *
 * Bibliography
 * [1] Federal Information Processing Standards Publication. Secure Hash Standard (SHS).
 *     FIPS PUB 180-4. Information Technology Laboratory. Gaithersburg, MD 20899-8900:
 *     National Institute of Standards and Technology, August 2015.
 **************************************************************************************************/
#include <algorithm/sha256.h>

#include <platform/contend.h>
#include <platform/unaligned.h>
#include <platform/byteswap.h>
#include <platform/memfill.h>



/*
 * SHA256 functions
 */
#define ROTR(N, X)       (((X)>>(N)) | ((X)<<((32)-(N))))
#define SHR(N, X)        ((X)>>(N))
#define CH(X, Y, Z)      (((X)&(Y)) ^ ((~(X))&(Z)))
#define MAJ(X, Y, Z)     (((X)&(Y)) ^ ((X)&(Z)) ^ ((Y)&(Z)))
#define SIGMA0(X)        (ROTR(2,X) ^ ROTR(13,X) ^ ROTR(22,X))
#define SIGMA1(X)        (ROTR(6,X) ^ ROTR(11,X) ^ ROTR(25,X))
#define S0(X)            (ROTR(7,X) ^ ROTR(18,X) ^ SHR(3,X))
#define S1(X)            (ROTR(17,X) ^ ROTR(19,X) ^ SHR(10,X))



/*
 * SHA256 constant
 */
static const uint32_t _sha256_k[64] =
{
	0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
	0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
	0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
	0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
	0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
	0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
	0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
	0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2
};



/*
 * Internal Functions
 */
static void _sha256_compress_chunk(struct sha256 *inst);



/*
 * External Functions
 */
void sha256_begin(struct sha256 *inst)
{
	CONTEND(inst != NULL);

	inst->len_filled = (size_t) 0;
	inst->len_total = (size_t) 0;

	inst->hash[0] = (uint32_t) 0x6a09e667;
	inst->hash[1] = (uint32_t) 0xbb67ae85;
	inst->hash[2] = (uint32_t) 0x3c6ef372;
	inst->hash[3] = (uint32_t) 0xa54ff53a;
	inst->hash[4] = (uint32_t) 0x510e527f;
	inst->hash[5] = (uint32_t) 0x9b05688c;
	inst->hash[6] = (uint32_t) 0x1f83d9ab;
	inst->hash[7] = (uint32_t) 0x5be0cd19;
}



void sha256_update(struct sha256 *inst, const void *data, size_t len)
{
	CONTEND(inst != NULL);
	CONTEND((len == 0) || (data != NULL));

	for (size_t data_index = (size_t) 0; data_index < len; ++data_index)
	{
		/* There shouldn't be any chunks larger than this because whenever a chunk reaches a length
		 * of 16 32-bit words it is processed and consumed. */
		CONTEND(inst->len_filled < (size_t) 64);

		/* Fill message schedule
		 *  - If the first 16 32-bit words are filled, process the chunk, then fill new chunk
		 *  - Otherwise, keep filling */
		inst->chunk[inst->len_filled] = ((const uint8_t*)data)[data_index];
		++inst->len_filled;
		++inst->len_total;

		if (inst->len_filled == (size_t) 64)
			_sha256_compress_chunk(inst);
	}
}



void sha256_finish(struct sha256 *inst, void *digest)
{
	CONTEND(inst != NULL);
	CONTEND(digest != NULL);

	/* There shouldn't be any unprocessed full chunks */
	CONTEND(inst->len_filled < (size_t) 64);

	/* Add padding to the message
	 *   - Append 0x80 to the data (1 byte)
	 *   - Append a number of zero bytes (variable size)
	 *   - Append length of original message in bits as 8-byte big endian value (8 bytes)
	 * The padded message should be an integer multiple of the 64-byte chunk size. */

	/* append 0x80 */
	inst->chunk[inst->len_filled] = (uint8_t) 0x80;
	inst->len_filled++;

	/* When has more than 56 bytes, padding results in current chunk (needs processing) and another
	 * chunk */
	if (inst->len_filled > (size_t) 56)
	{
		/* zero pad towards end of the current chunk */
		mem_zeropad(inst->chunk, (size_t) 64, inst->len_filled);
		inst->len_filled = (size_t) 64;

		/* process current chunk */
		_sha256_compress_chunk(inst);
	}

	/* zero pad towards the beginning of the 8-byte big endian length in bits */
	mem_zeropad(inst->chunk, (size_t) 56, inst->len_filled);

	/* add the message length in bits as 8-byte big endian value */
	uint64_t total_length_bits = (uint64_t) inst->len_total *8;
	unalign_u64(byteswap_to_u64be(total_length_bits), &inst->chunk[56]);

	inst->len_filled = (size_t) 64;
	_sha256_compress_chunk(inst);

	/* always output as big endian */
	for (size_t t = (size_t) 0; t < (size_t) 8; ++t)
		unalign_u32(byteswap_to_u32be(inst->hash[t]), &((uint8_t*)digest)[t*sizeof(uint32_t)]);
}



static void _sha256_compress_chunk(struct sha256 *inst)
{
	/*
	 * internal function, parameter checks not required
	 */


	/* Chunk should be full */
	CONTEND(inst->len_filled == (size_t) 64);


	/* Prepare the message schedule
	 * Obtain the first 16 32-bit words from chunk
	 * Extend the first 16 32-bit words w[0..15] into the remaining 48 32-bit words w[16..63] */
	for (size_t t = (size_t) 0; t < (size_t) 16; ++t)
		inst->w[t] = byteswap_from_u32be(align_u32(&inst->chunk[t*sizeof(uint32_t)]));

	for (size_t t = (size_t) 16; t < (size_t) 64; ++t)
		inst->w[t] = S1(inst->w[t-2]) + inst->w[t-7] + S0(inst->w[t-15]) + inst->w[t-16];

	/* Initialize the working variables with the previous hash value */
	inst->a = inst->hash[0];
	inst->b = inst->hash[1];
	inst->c = inst->hash[2];
	inst->d = inst->hash[3];
	inst->e = inst->hash[4];
	inst->f = inst->hash[5];
	inst->g = inst->hash[6];
	inst->h = inst->hash[7];

	/* SHA256 compression loop */
	for (size_t t = (size_t) 0; t < (size_t) 64; ++t)
	{
		/* temporary variables */
		uint32_t t1;
		uint32_t t2;

		t1 = inst->h + SIGMA1(inst->e) + CH(inst->e,inst->f,inst->g) + _sha256_k[t] + inst->w[t];
		t2 = SIGMA0(inst->a) + MAJ(inst->a,inst->b,inst->c);
		inst->h = inst->g;
		inst->g = inst->f;
		inst->f = inst->e;
		inst->e = inst->d + t1;
		inst->d = inst->c;
		inst->c = inst->b;
		inst->b = inst->a;
		inst->a = t1 + t2;
	}

	/* add the compressed chunk to the current hash value */
	inst->hash[0] += inst->a;
	inst->hash[1] += inst->b;
	inst->hash[2] += inst->c;
	inst->hash[3] += inst->d;
	inst->hash[4] += inst->e;
	inst->hash[5] += inst->f;
	inst->hash[6] += inst->g;
	inst->hash[7] += inst->h;

	/* the chunk is consumed */
	inst->len_filled = (size_t) 0;
}

