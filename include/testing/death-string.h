/***************************************************************************************************
 * Assertion String
 *
 * When verifying death tests, the test framework looks for the assertion string in the standard
 * error output. If the string is found, it means the unit has correctly captured and reported the
 * failure, and correctly terminated as a result. Otherwise, the unit does not protect itself
 * against incorrect inputs and thus fails the death test.
 **************************************************************************************************/
#ifndef H1A6C9BDA_7A80_4900_8F55_5F67C3BE0C3B
#define H1A6C9BDA_7A80_4900_8F55_5F67C3BE0C3B

#define TESTING_DEATH_STRING  "assertion failed"

#endif /* H1A6C9BDA_7A80_4900_8F55_5F67C3BE0C3B */
