# source/protocol/ethernet/subdir.mk
DEFS-$(MENU_PROTO_ETH) += CONFIG_ETH_MAX_PAYLOAD_SIZE=$(MENU_PROTO_ETH_MAXPAYLOAD)
SRC-$(MENU_PROTO_ETH) += eth-addr-broadcast.c
SRC-$(MENU_PROTO_ETH_PAD) += eth-pad-packet.c
SRC-$(MENU_PROTO_ETH_CHECKSUM) += eth-checksum.c
