/***************************************************************************************************
 * Thread and Interrupt Safe Memory Filling Routines
 *
 * This header provides thread and interrupt safe equivalents to replace the unsafe ones in the
 * standard library.
 **************************************************************************************************/
#include <platform/memfill.h>

#include <platform/contend.h>
#include <stdint.h>



void mem_zeropad(void *buf, size_t buf_size, size_t start)
{
	CONTEND(((buf_size == 0) && (start == 0)) || (buf != NULL));

	/*
	 * Courtesy assertion
	 * This assertion is not required for the correct operation of this function, but performed
	 * nonetheless to help catch bugs in the caller.
	 */
	CONTEND(start <= buf_size);

	uint8_t *byte = (uint8_t*) buf;

	for (size_t index = start; index < buf_size; ++index)
		byte[index] = (uint8_t) 0;
}



void mem_copy(void *to, size_t to_start, const void *from, size_t from_start, size_t size)
{
	CONTEND(((size == 0) && (to_start ==0) && (from_start == 0)) ||
			((to != NULL) && (from != NULL)));

	uint8_t *to_byte = (uint8_t*) to;
	const uint8_t *from_byte = (const uint8_t*) from;

	for (size_t index = 0; index < size; ++index)
		to_byte[index + to_start] = from_byte[index + from_start];
}
