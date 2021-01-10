/***************************************************************************************************
 * Ethernet Protocol
 * Software Checksum Helper
 **************************************************************************************************/
#include <protocol/ethernet/eth-helper.h>
#include <algorithm/crc.h>
#include <platform/byteswap.h>
#include <platform/unaligned.h>
#include <platform/contend.h>



size_t eth_append_checksum(void *packet_buf, size_t packet_size)
{
	/* parameter assertion duty deffered to subfunction call */
	CONTEND(packet_size + ETH_TRAILER_SIZE <= ETH_BUFFER_SIZE);

	struct crc32_lf instance;

	crc32_lf_begin(&instance, &CRC32_IEEE);
	crc32_lf_update(&instance, packet_buf, packet_size);
	uint32_t crc32_result = crc32_lf_finish(&instance);

	/*
	 * Frame check sequence is in big endian
	 */
	uint8_t *checksum_dest = (uint8_t*)packet_buf + packet_size;
	unalign_u32(byteswap_to_u32be(crc32_result), checksum_dest);

	return packet_size +ETH_TRAILER_SIZE;
}



bool eth_verify_checksum(const void *packet_buf, size_t packet_size)
{
	struct crc32_lf instance;

	crc32_lf_begin(&instance, &CRC32_IEEE);
	crc32_lf_update(&instance, packet_buf, packet_size);
	uint32_t crc32_result = crc32_lf_finish(&instance);

	/*
	 * A valid CRC32-IEEE checksum complements checksummed data resulting in the combined checksum
	 * of zero.
	 */
	return crc32_result == (uint32_t) 0;
}
