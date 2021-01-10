/*
 * SHA256 Unit Tests
 */
#include <algorithm/sha256.h>
#include <testing/death-string.h>
#include <googletest/gmock.h>



TEST(SHA256, DeathTest) {
	struct sha256_inst dummy_instance;
	uint8_t dummy_result[SHA256_DIGEST_SIZE];

	EXPECT_DEATH(sha256_begin(nullptr),  TESTING_DEATH_STRING);

	EXPECT_DEATH(sha256_update(nullptr, nullptr, 1), TESTING_DEATH_STRING);
	EXPECT_DEATH(sha256_update(&dummy_instance, nullptr, 1), TESTING_DEATH_STRING);

	EXPECT_DEATH(sha256_finish(nullptr, nullptr), TESTING_DEATH_STRING);
	EXPECT_DEATH(sha256_finish(nullptr, dummy_result), TESTING_DEATH_STRING);
	EXPECT_DEATH(sha256_finish(&dummy_instance, nullptr), TESTING_DEATH_STRING);
}



TEST(SHA256, EmptyVector) {
	struct sha256_inst instance;
	uint8_t result[SHA256_DIGEST_SIZE];

	sha256_begin(&instance);
	sha256_finish(&instance, &result);

	EXPECT_THAT(result, testing::ElementsAre(
			0xe3, 0xb0, 0xc4, 0x42, 0x98, 0xfc, 0x1c, 0x14,
			0x9a, 0xfb, 0xf4, 0xc8, 0x99, 0x6f, 0xb9, 0x24,
			0x27, 0xae, 0x41, 0xe4, 0x64, 0x9b, 0x93, 0x4c,
			0xa4, 0x95, 0x99, 0x1b, 0x78, 0x52, 0xb8, 0x55));
}



TEST(SHA256, String) {
	struct sha256_inst instance;
	uint8_t result[SHA256_DIGEST_SIZE];

	sha256_begin(&instance);
	sha256_update(&instance, "The quick brown fox jumps over the lazy dog.", 44);
	sha256_finish(&instance, &result);

	EXPECT_THAT(result, testing::ElementsAre(
			0xef, 0x53, 0x7f, 0x25, 0xc8, 0x95, 0xbf, 0xa7, 0x82, 0x52, 0x65, 0x29,
			0xa9, 0xb6, 0x3d, 0x97, 0xaa, 0x63, 0x15, 0x64, 0xd5, 0xd7, 0x89, 0xc2,
			0xb7, 0x65, 0x44, 0x8c, 0x86, 0x35, 0xfb, 0x6c));
}



/*
 * Includes generated test cases
 */
#include "sha256.inc"

