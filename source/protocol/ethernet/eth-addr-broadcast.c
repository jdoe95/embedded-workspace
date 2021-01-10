/***************************************************************************************************
 * Ethernet Protocol
 * Medium Access Control Address
 **************************************************************************************************/
#include <protocol/ethernet/eth-addr.h>



/*
 * Addresses all connected Ethernet nodes
 */
const struct eth_addr ETH_ADDR_BROADCAST =
{
	.data = {
		[0] = 0xFF,
		[1] = 0xFF,
		[2] = 0xFF,
		[3] = 0xFF,
		[4] = 0xFF,
		[5] = 0xFF
	}
};
