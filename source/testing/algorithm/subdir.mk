# source/testing/algorithm/subdir.mk
DIR-y += crc
SRC-$(MENU_TEST_ALGO_SHA256) += sha256.cc

$(D_HERE)/sha256.inc:
	$(@D)/sha256-cases.sh $@
