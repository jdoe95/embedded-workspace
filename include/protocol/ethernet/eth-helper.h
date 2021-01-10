/***************************************************************************************************
 * Ethernet Protocol
 * Software Helpers
 *
 * Software helpers complement platforms that lack the corresponding hardware feature.
 **************************************************************************************************/
#ifndef HF17FB076_7227_4488_A3F8_3D31574036B7
#define HF17FB076_7227_4488_A3F8_3D31574036B7

#include <stddef.h>
#include <stdbool.h>
#include <protocol/ethernet/eth-addr.h>



/*
 * When platform uses software based packet buffers, use this to define a buffer with minimum size
 * so that the software helper routines don't overflow the buffer.
 */
#define ETH_BUFFER_SIZE  (CONFIG_ETH_MAX_PAYLOAD_SIZE +ETH_HEADER_SIZE +ETH_TRAILER_SIZE)

#define ETH_MIN_PACKET_SIZE   (64)
#define ETH_HEADER_SIZE       (14)
#define ETH_TRAILER_SIZE      (4)

#if !defined(CONFIG_ETH_MAX_PAYLOAD_SIZE)
#	define CONFIG_ETH_MAX_PAYLOAD_SIZE    (1500)
#	warning Ethernet maximum payload size set to 1500.
#endif



#if defined(__GNUC__)
struct eth_header
{
	struct eth_addr dest;
	struct eth_addr source;
	uint16_t ethertype;
} __attribute__((packed));

#else
#	error "Unable to pack struct".
#endif



#if defined(__cplusplus)
extern "C" {
#endif



size_t eth_pad_packet(void *packet_buf, size_t packet_size);
size_t eth_append_checksum(void *packet_buf, size_t packet_size);
bool eth_verify_checksum(const void *packet_buf, size_t packet_size);



#if defined(__cplusplus)
}
#endif



#endif /* HF17FB076_7227_4488_A3F8_3D31574036B7 */
