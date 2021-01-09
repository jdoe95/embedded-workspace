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

TEST(MemCopy, DeathTest)
{
	uint8_t to_dummy;
	uint8_t from_dummy;
	EXPECT_DEATH(mem_copy(nullptr, 0, nullptr, 0, 1), TESTING_DEATH_STRING);
	EXPECT_DEATH(mem_copy(&to_dummy, sizeof(to_dummy), nullptr, 0, 1), TESTING_DEATH_STRING);
	EXPECT_DEATH(mem_copy(nullptr, 0, &from_dummy, sizeof(from_dummy), 1), TESTING_DEATH_STRING);
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

TEST(MemCopy, Test1)
{
	const uint8_t input[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
	uint8_t output[8] = {0};

	mem_copy(output, 0, input, 0, 8);

	EXPECT_THAT(output, testing::ElementsAre(
			0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88));
}

TEST(MemCopy, Test2)
{
	const uint8_t input[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
	uint8_t output[8] = {0};

	mem_copy(output, 0, input, 4, 4);

	EXPECT_THAT(output, testing::ElementsAre(
			0x55, 0x66, 0x77, 0x88, 0x00, 0x00, 0x00, 0x00));
}

TEST(MemCopy, Test3)
{
	const uint8_t input[8] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88};
	uint8_t output[8] = {0};

	mem_copy(output, 4, input, 0, 4);

	EXPECT_THAT(output, testing::ElementsAre(
			0x00, 0x00, 0x00, 0x00, 0x11, 0x22, 0x33, 0x44));
}
