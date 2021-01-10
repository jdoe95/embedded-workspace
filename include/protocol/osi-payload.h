/***************************************************************************************************
 * Payload Descriptors
 *
 * Payloads are common concepts refactored from protocol layers.
 **************************************************************************************************/
#ifndef H205A5E60_2E2A_4CCE_A006_E0A99AAD1CDF
#define H205A5E60_2E2A_4CCE_A006_E0A99AAD1CDF

#include <stddef.h>



/*
 * Ingress payload descriptor
 * Describes payload data to upper protocol layers.
 */
struct osi_payload_ingress
{
	const void *payload;
	size_t payload_size;
};



/*
 * Egress payload descriptor
 * Describes payload buffer to upper payload layers.
 */
struct osi_payload_egress
{
	void *payload;
	size_t max_payload;
};


#endif /* H205A5E60_2E2A_4CCE_A006_E0A99AAD1CDF */
