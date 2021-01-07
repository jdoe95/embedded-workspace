/***************************************************************************************************
 * Cyclic Redundancy Check
 * Supports various CRC32, CRC16, and CRC8
 *
 * CRC treats the input message as a Galois Field 2 polynomial I(X) mapped to a long bit sequence.
 * I(X) is then padded by 8, 16, or 32 zeros depending on the CRC version, resulting in M(X).
 * M(X) is divided by divisor G(X) using Euclidian division of polynomials, resulting in remainder
 * R(X) as the CRC.
 *
 * There is no authortarian CRC standard. Variations include the divisor G(X), shifting direction,
 * initial remainder value, wether the output is inverted etc. The header provides a common
 * interface to support a variety of CRC variants.
 *
 * The Least-Significant-bit-first (LSb-first) and Most-Significant-bit-first (MSb-first) variants
 * use different shifting functions. They are typed separately so that the compiler can prevent
 * intermixing of LSb-first and MSb-first method calls.
 **************************************************************************************************/
#ifndef H10C2DBAA_4D00_42B3_92AE_9AAACC040F58
#define H10C2DBAA_4D00_42B3_92AE_9AAACC040F58

#include <stdint.h>
#include <stddef.h>



/*
 * Forward declarations of CRC variant parametric block
 * The structs contain hidden CRC variant information.
 */
/* MSb first variants */
struct crc32_mf_info;
struct crc16_mf_info;
struct crc8_mf_info;

/* LSb first variants */
struct crc32_lf_info;
struct crc16_lf_info;
struct crc8_lf_info;



/*
 * CRC catalog
 * Used to initialize the CRC calculator into a CRC variant.
 */
#if defined(__cplusplus)
extern "C" {
#endif

extern const struct crc32_lf_info CRC32_IEEE;   /* [G=0x104C11DB7] IEEE 802.3 Ethernet */
extern const struct crc16_lf_info CRC16_MODBUS; /* [G=0x18005] MODBUS */

#if defined(__cplusplus)
}
#endif



/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc32_mf
{
	/* variant parametric block */
	const struct crc32_mf_info *info;

	/* intermediate remainder */
	uint32_t remainder;
};

/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc16_mf
{
	/* variant parametric block */
	const struct crc16_mf_info *info;

	/* intermediate remainder */
	uint16_t remainder;
};

/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc8_mf
{
	/* variant parametric block */
	const struct crc8_mf_info *info;

	/* intermediate remainder */
	uint8_t remainder;
};

/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc32_lf
{
	/* variant parametric block */
	const struct crc32_lf_info *info;

	/* intermediate remainder */
	uint32_t remainder;
};

/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc16_lf
{
	/* variant parametric block */
	const struct crc16_lf_info *info;

	/* intermediate remainder */
	uint16_t remainder;
};

/*
 * CRC calculator state data
 * ALL MEMBERS ARE PRIVATE
 */
struct crc8_lf
{
	/* variant parametric block */
	const struct crc8_lf_info *info;

	/* intermediate remainder */
	uint8_t remainder;
};




#if defined (__cplusplus)
extern "C" {
#endif

/* prepares calculator */
void crc32_mf_begin(struct crc32_mf *inst, const struct crc32_mf_info *info);
void crc16_mf_begin(struct crc16_mf *inst, const struct crc16_mf_info *info);
void crc8_mf_begin(struct crc8_mf *inst, const struct crc8_mf_info *info);
void crc32_lf_begin(struct crc32_lf *inst, const struct crc32_lf_info *info);
void crc16_lf_begin(struct crc16_lf *inst, const struct crc16_lf_info *info);
void crc8_lf_begin(struct crc8_lf *inst, const struct crc8_lf_info *info);

/* feeds data into the calculator, can be used multiple times */
void crc32_mf_update(struct crc32_mf *inst, const void *data, size_t len);
void crc16_mf_update(struct crc16_mf *inst, const void *data, size_t len);
void crc8_mf_update(struct crc8_mf *inst, const void *data, size_t len);
void crc32_lf_update(struct crc32_lf *inst, const void *data, size_t len);
void crc16_lf_update(struct crc16_lf *inst, const void *data, size_t len);
void crc8_lf_update(struct crc8_lf *inst, const void *data, size_t len);

/* finishes calculation and returns CRC in platform native endianness */
uint32_t crc32_mf_finish(struct crc32_mf *inst);
uint16_t crc16_mf_finish(struct crc16_mf *inst);
uint8_t crc8_mf_finish(struct crc8_mf *inst);
uint32_t crc32_lf_finish(struct crc32_lf *inst);
uint16_t crc16_lf_finish(struct crc16_lf *inst);
uint8_t crc8_lf_finish(struct crc8_lf *inst);

#if defined (__cplusplus)
}
#endif

#endif /* H10C2DBAA_4D00_42B3_92AE_9AAACC040F58 */
