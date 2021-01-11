# source/platform/subdir.mk
DEFS-$(MENU_PLAT_NOASSERT) += CONFIG_NOASSERT=1
DEFS-$(MENU_PLAT_ENDIAN_BIG) += CONFIG_ENDIANNESS=ENDIAN_BIG
DEFS-$(MENU_PLAT_ENDIAN_LITTLE) += CONFIG_ENDIANNESS=ENDIAN_LITTLE
DEFS-$(MENU_PLAT_ENDIAN_PDP) += CONFIG_ENDIANNESS=ENDIAN_PDP
DEFS-$(MENU_PLAT_ENDIAN_HS316) += CONFIG_ENDIANNESS=ENDIAN_HS316

SRC-$(MENU_PLAT_BYTESWAP) += byteswap.c

ifneq ($(MENU_PLAT_BYTESWAP_NOGENERIC),y)
SRC-$(MENU_PLAT_BYTESWAP) += byteswap-generic.c
endif

ifneq ($(MENU_PLAT_BITREVERSE_NOGENERIC),y)
SRC-$(MENU_PLAT_BITREVERSE) += bitreverse.c
endif

SRC-$(MENU_PLAT_MEMFILL) += memfill.c
SRC-$(MENU_PLAT_UNALIGNED) += unaligned.c

DIR-y += posixos
