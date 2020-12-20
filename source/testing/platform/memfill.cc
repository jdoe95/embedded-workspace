/*
 * Memfill Unit Tests
 */
#include <googletest/gmock.h>

#include <platform/memfill.h>
#include <testing/death-string.h>



TEST(MemZeropad, DeathTest)
{
	EXPECT_DEATH(mem_zeropad(nullptr, 1, 1), TESTING_DEATH_STRING);
}

TEST(MemZeropad, Test1)
{
	uint8_t test_vector[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};

	mem_zeropad(test_vector, 8, 4);

	EXPECT_THAT(test_vector, testing::ElementsAre(
			0x11, 0x22, 0x33, 0x44, 0x00, 0x00, 0x00, 0x00));
}

TEST(MemZeropad, Test2)
{
	uint8_t test_vector[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};

	mem_zeropad(test_vector, 4, 0);

	EXPECT_THAT(test_vector, testing::ElementsAre(
			0x00, 0x00, 0x00, 0x00, 0x55, 0x66, 0x77, 0x88));
}
