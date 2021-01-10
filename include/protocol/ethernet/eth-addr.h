/***************************************************************************************************
 * Ethernet Protocol
 * Medium Access Control Address
 **************************************************************************************************/
#ifndef H4BCAFFCC_7EAC_4451_B32C_7E7C2B10F698
#define H4BCAFFCC_7EAC_4451_B32C_7E7C2B10F698

#include <stdint.h>
#include <stddef.h>



/* readability */
#define ETH_ADDR_SIZE   (6)

#if defined (__GNUC__)
struct eth_addr
{
	uint8_t data[ETH_ADDR_SIZE];
} __attribute__((packed));

#else
#	error Unable to pack struct.
#endif



#if defined(__cplusplus)
extern "C" {
#endif

/*
 * Only lists well known address constants
 */
/* FF-FF-FF-FF-FF-FF Broadcast address */
extern const struct eth_addr ETH_ADDR_BROADCAST;

#if defined(__cplusplus)
}
#endif


#endif /* H4BCAFFCC_7EAC_4451_B32C_7E7C2B10F698 */
