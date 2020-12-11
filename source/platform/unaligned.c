/*
 * Unaligned Integer Access Functions
 *
 * Directly casting between pointer-to-integer types is implementation-defined behavior and can
 * cause memory-access problems if the pointer is not aligned to the boundary of the integer type.
 *
 * Provides routines to load or store integer types into byte sequences, which may be unaligned.
 * The byte sequences are in platform native endianness.
 */
#include <platform/unaligned.h>

#include <platform/contend.h>
#include <stddef.h>


/*
 * The compiler generates byte instructions to access members of packed structs.
 * This implementation takes advantage of that.
 */



#if defined (__GNUC__)

#	if defined(UINT16_MAX)
struct __attribute__((packed)) unaligned_u16
{
	uint16_t val;
};

uint16_t align_u16(const void *data)
{
	CONTEND(data != NULL);
	return ((const struct unaligned_u16*)data)->val;
}

void unalign_u16(uint16_t val, void *data)
{
	CONTEND(data != NULL);
	((struct unaligned_u16*)data)->val = val;
}
#	endif /* defined(UINT16_MAX) */



#	if defined(UINT32_MAX)
struct __attribute__((packed)) unaligned_u32
{
	uint32_t val;
};

uint32_t align_u32(const void *data)
{
	CONTEND(data != NULL);
	return ((const struct unaligned_u32*)data)->val;
}

void unalign_u32(uint32_t val, void *data)
{
	CONTEND(data != NULL);
	((struct unaligned_u32*)data)->val = val;
}
#	endif /* defined(UINT32_MAX) */



#	if defined(UINT64_MAX)
struct __attribute__((packed)) unaligned_u64
{
	uint64_t val;
};

uint64_t align_u64(const void *data)
{
	CONTEND(data != NULL);
	return ((const struct unaligned_u64*)data)->val;
}

void unalign_u64(uint64_t val, void *data)
{
	CONTEND(data != NULL);
	((struct unaligned_u64*)data)->val = val;
}
#	endif /* defined(UINT64_MAX) */



#else
#	error Not implemented.
#endif /* defined(__GNUC__) */
