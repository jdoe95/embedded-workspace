/***************************************************************************************************
 * Ethernet Protocol
 * Packet Composition and Dissection
 *
 * The Ethernet packet composition is performed inside the Ethernet driver in a platform dependent
 * manner. The Ethernet platform driver calls higher layer dissectors to process received packets.
 **************************************************************************************************/
#ifndef H53030A80_93DB_4439_9432_6AD66DB21EC3
#define H53030A80_93DB_4439_9432_6AD66DB21EC3

#include <stdint.h>
#include <stddef.h>
#include <protocol/osi-payload.h>



/*
 * Ethernet Interface
 * The opaque struct is instantiated in the Ethernet driver internally. Members are inaccessible
 * elsewhere.
 */
struct eth_if;



/*
 * Ethernet packet composition parameters
 */
struct eth_comp_param
{
	uint16_t ethertype;                 /* EtherType in transmit packet */
	const struct eth_addr *dest;        /* destination address of the transmit packet */
	size_t payload_size;                /* size of transmit payload */
};

/*
 * Ethernet packet compositor
 * The opaque struct is instantiated in the Ethernet driver internally. Members are inaccessible
 * elsewhere.
 */
struct eth_comp;



/*
 * Ethernet packet dissection parameters
 */
struct eth_diss_param
{
	uint16_t ethertype;                 /* EtherType in received packet */
	const struct eth_addr *source;      /* source address of the received packet */
	struct osi_payload_ingress payload; /* payload in received packet */
};

/*
 * Ethernet packet dissector
 * The opaque struct is instantiated in the Ethernet driver internally. Members are inaccessible
 * elsewhere.
 */
struct eth_diss;



/*
 * Payload type (EtherType)
 */
#define ETH_PAYLOAD_IPV6     ((uint16_t) 0x86DD) /* Internet Protocol Version 6 */
#define ETH_PAYLOAD_LLDP     ((uint16_t) 0x88CC) /* Link Layer Discovery Protocol */
#define ETH_PAYLOAD_FLOWCTRL ((uitn16_t) 0x8808) /* Ethernet flow control */
#define ETH_PAYLOAD_VLAN     ((uint16_t) 0x8100) /* Virtual Local Area Network */
#define ETH_PAYLOAD_MACSEC   ((uint16_t) 0x88E5) /* MAC Layer Security */
#define ETH_PAYLOAD_PTP      ((uint16_t) 0x88F7) /* Precision Time Control */
#define ETH_PAYLOAD_EAPOL    ((uint16_t) 0x888E) /* Extensible Authentication Protocol */



#if defined(__cplusplus)
extern "C" {
#endif



/*
 * Ethernet packet composition functions exposed to upper protocol layers.
 */
struct eth_comp* eth_comp_acquire(struct eth_if *iface);
void eth_comp_commit(struct eth_comp *comp);
void eth_comp_param(struct eth_comp *comp, const struct eth_comp_param *param);
void eth_comp_payload(struct eth_comp *comp, struct osi_payload_egress *payload);



/*
 * Ethernet packet dissection functions exposed to upper protocol layers.
 */
struct eth_diss* eth_diss_acquire(struct eth_if *iface);
void eth_diss_param(struct eth_diss *diss, struct eth_diss_param *param);
void eth_diss_release(struct eth_diss *diss);



#if defined(__cplusplus)
}
#endif

#endif /* H53030A80_93DB_4439_9432_6AD66DB21EC3 */
