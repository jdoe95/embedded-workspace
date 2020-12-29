/*
 * Bitreverse unit tests
 */
#include <googletest/gtest.h>

#include <platform/bitreverse.h>



#if defined(UINT8_MAX)
TEST(Bitreverse, U8)
{
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x1A)), static_cast<uint8_t>(0x58));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x79)), static_cast<uint8_t>(0x9E));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x37)), static_cast<uint8_t>(0xEC));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x78)), static_cast<uint8_t>(0x1E));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x38)), static_cast<uint8_t>(0x1C));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x65)), static_cast<uint8_t>(0xA6));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xDE)), static_cast<uint8_t>(0x7B));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x31)), static_cast<uint8_t>(0x8C));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xD9)), static_cast<uint8_t>(0x9B));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x5E)), static_cast<uint8_t>(0x7A));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xA3)), static_cast<uint8_t>(0xC5));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xE1)), static_cast<uint8_t>(0x87));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xD4)), static_cast<uint8_t>(0x2B));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x5B)), static_cast<uint8_t>(0xDA));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xE1)), static_cast<uint8_t>(0x87));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x5F)), static_cast<uint8_t>(0xFA));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xDB)), static_cast<uint8_t>(0xDB));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x54)), static_cast<uint8_t>(0x2A));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0x79)), static_cast<uint8_t>(0x9E));
	EXPECT_EQ(bitreverse_u8(static_cast<uint8_t>(0xFC)), static_cast<uint8_t>(0x3F));
}
#endif



#if defined(UINT16_MAX)
TEST(Bitreverse, U16)
{
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xE46B)), static_cast<uint16_t>(0xD627));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x360A)), static_cast<uint16_t>(0x506C));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x4974)), static_cast<uint16_t>(0x2E92));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x8A63)), static_cast<uint16_t>(0xC651));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x538A)), static_cast<uint16_t>(0x51CA));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xE0D8)), static_cast<uint16_t>(0x1B07));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x6023)), static_cast<uint16_t>(0xC406));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xF130)), static_cast<uint16_t>(0x0C8F));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xC958)), static_cast<uint16_t>(0x1A93));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xCB44)), static_cast<uint16_t>(0x22D3));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x4B83)), static_cast<uint16_t>(0xC1D2));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x4DCB)), static_cast<uint16_t>(0xD3B2));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x719F)), static_cast<uint16_t>(0xF98E));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xD411)), static_cast<uint16_t>(0x882B));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x5E8A)), static_cast<uint16_t>(0x517A));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x10E8)), static_cast<uint16_t>(0x1708));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x3A4D)), static_cast<uint16_t>(0xB25C));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xF6E8)), static_cast<uint16_t>(0x176F));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0xC93D)), static_cast<uint16_t>(0xBC93));
	EXPECT_EQ(bitreverse_u16(static_cast<uint16_t>(0x5B92)), static_cast<uint16_t>(0x49DA));
}
#endif



#if defined(UINT32_MAX)
TEST(Bitreverse, U32)
{
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x8721CA38)), static_cast<uint32_t>(0x1C5384E1));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x260A0BE2)), static_cast<uint32_t>(0x47D05064));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xB3B5F3EE)), static_cast<uint32_t>(0x77CFADCD));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x1EC7ADD5)), static_cast<uint32_t>(0xABB5E378));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xC6940799)), static_cast<uint32_t>(0x99E02963));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x6D0843D1)), static_cast<uint32_t>(0x8BC210B6));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xB1DC10F2)), static_cast<uint32_t>(0x4F083B8D));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xDDF71EB9)), static_cast<uint32_t>(0x9D78EFBB));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x245115D8)), static_cast<uint32_t>(0x1BA88A24));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x3BEF32FA)), static_cast<uint32_t>(0x5F4CF7DC));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x40D0A447)), static_cast<uint32_t>(0xE2250B02));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x09DF85F5)), static_cast<uint32_t>(0xAFA1FB90));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x699CB2D7)), static_cast<uint32_t>(0xEB4D3996));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xDFD2E992)), static_cast<uint32_t>(0x49974BFB));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x36F4F3E9)), static_cast<uint32_t>(0x97CF2F6C));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x4200DAFB)), static_cast<uint32_t>(0xDF5B0042));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xBEC142D1)), static_cast<uint32_t>(0x8B42837D));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0x817CF5E7)), static_cast<uint32_t>(0xE7AF3E81));
	EXPECT_EQ(bitreverse_u32(static_cast<uint32_t>(0xE0DBED19)), static_cast<uint32_t>(0x98B7DB07));
}
#endif



#if defined(UINT64_MAX)
TEST(Bitreverse, U64)
{
	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x4D6E04BA40E1B277)),
	    static_cast<uint64_t>(0xEE4D87025D2076B2));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xACE28B64AB38E998)),
	    static_cast<uint64_t>(0x19971CD526D14735));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xED720A316F34DD83)),
	    static_cast<uint64_t>(0xC1BB2CF68C504EB7));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xA9A7608DF7447F59)),
	    static_cast<uint64_t>(0x9AFE22EFB106E595));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x34B92138175432D5)),
	    static_cast<uint64_t>(0xAB4C2AE81C849D2C));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x21548F4AE0D9A77A)),
	    static_cast<uint64_t>(0x5EE59B0752F12A84));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xD478A2E954B07A75)),
	    static_cast<uint64_t>(0xAE5E0D2A97451E2B));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xE4053057285859BA)),
	    static_cast<uint64_t>(0x5D9A1A14EA0CA027));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x82B64BA129976BC4)),
	    static_cast<uint64_t>(0x23D6E99485D26D41));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x3C5B25B4E144BB9E)),
	    static_cast<uint64_t>(0x79DD22872DA4DA3C));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xC925E0F823E2E237)),
	    static_cast<uint64_t>(0xEC4747C41F07A493));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xBC8E65F97309CC7F)),
	    static_cast<uint64_t>(0xFE3390CE9FA6713D));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x413F616DE1A2559D)),
	    static_cast<uint64_t>(0xB9AA4587B686FC82));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xC68E1067EFD6F447)),
	    static_cast<uint64_t>(0xE22F6BF7E6087163));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x3336323F16ADA8BE)),
	    static_cast<uint64_t>(0x7D15B568FC4C6CCC));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x3F5779A307B0135E)),
	    static_cast<uint64_t>(0x7AC80DE0C59EEAFC));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x7C81FFCA01CC5A30)),
	    static_cast<uint64_t>(0x0C5A338053FF813E));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x972B13F51A5C558B)),
	    static_cast<uint64_t>(0xD1AA3A58AFC8D4E9));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0xD3A58FA24618216D)),
	    static_cast<uint64_t>(0xB684186245F1A5CB));

	EXPECT_EQ(bitreverse_u64(static_cast<uint64_t>(0x7CDB6EB01D3BC8A8)),
	    static_cast<uint64_t>(0x1513DCB80D76DB3E));

}
#endif
