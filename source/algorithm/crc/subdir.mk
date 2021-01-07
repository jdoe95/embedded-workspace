# source/algorithm/crc/subdir.mk
DEFS-$(MENU_ALGO_CRC_TABLE) += CONFIG_CRC_TABLE=1

SRC-$(MENU_ALGO_CRC32_MF) += crc32-mf.c
SRC-$(MENU_ALGO_CRC32_LF) += crc32-lf.c
SRC-$(MENU_ALGO_CRC16_MF) += crc16-mf.c
SRC-$(MENU_ALGO_CRC16_LF) += crc16-lf.c
SRC-$(MENU_ALGO_CRC8_MF) += crc8-mf.c
SRC-$(MENU_ALGO_CRC8_LF) += crc8-lf.c

SRC-$(MENU_ALGO_CRC32_TABLE_IEEE) += crc32-table-ieee.c
SRC-$(MENU_ALGO_CRC16_TABLE_MODBUS) += crc16-table-modbus.c

SRC-$(MENU_ALGO_CRC32_IEEE) += crc32-ieee.c
SRC-$(MENU_ALGO_CRC16_MODBUS) += crc16-modbus.c
