/***************************************************************************************************
 * Ethernet Protocol
 * Software Zero Padding Helper
 **************************************************************************************************/
#include <protocol/ethernet/eth-helper.h>
#include <platform/memfill.h>



/* Minimum size to pad into */
#define ETH_PAD_SIZE   (60)


/* sanity check */
#if ETH_PAD_SIZE > ETH_BUFFER_SIZE
#	error Padding results in Ethernet buffer overflow.
#endif



size_t eth_pad_packet(void *packet_buf, size_t packet_size)
{
	/* parameter assertion duty deferred to subfunction call */

	if (packet_size < ETH_PAD_SIZE)
	{
		mem_zeropad(packet_buf, ETH_PAD_SIZE, packet_size);
		packet_size = ETH_PAD_SIZE;
	}

	return packet_size;
}
