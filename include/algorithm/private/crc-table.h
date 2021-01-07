/***************************************************************************************************
 * Cyclic Redundancy Check
 * Private Header: CRC Table
 *
 * CRC tables can be shared among CRC variants. Include this header to define a CRC table.
 **************************************************************************************************/
#ifndef HBDFDD47C_D895_4D84_A18B_C6D371529713
#define HBDFDD47C_D895_4D84_A18B_C6D371529713

#include <stdint.h>



#define CRC_TABLE_SIZE (256)



#if defined(__cplusplus)
extern "C" {
#endif



extern const uint32_t CRC32_TABLE_IEEE[CRC_TABLE_SIZE];
extern const uint16_t CRC16_TABLE_MODBUS[CRC_TABLE_SIZE];



#if defined(__cplusplus)
}
#endif

#endif /* HBDFDD47C_D895_4D84_A18B_C6D371529713 */
