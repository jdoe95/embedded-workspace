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
