/***************************************************************************************************
 * Standalone Assertion
 *
 * The assert() function in the C standard header depends on functions in the C standard library
 * that are not available in a freestanding environment, for example, write() to print the string to
 * stdout. In addition, assert() causes __FILE__ and __LINE__ literals to be complied. This header
 * introduces a standalone CONTEND() as an alternative. The CONTEND() macro automatically detects
 * if it is compiled for a hosted environment and invokes the assertion handler correspondingly.
 **************************************************************************************************/
#ifndef H30D103CF_33CB_472A_A14E_1FF09A1E0F2E
#define H30D103CF_33CB_472A_A14E_1FF09A1E0F2E



/* Build disables assertion */
#if CONFIG_NOCONTEND
#	define CONTEND(COND) ((void) 0)



/* hosted environment, use standard library assert() */
#elif __STDC_HOSTED__ && (!CONFIG_USE_CONTEND_FAIL)
/*
 * makes sure "assertion failed" string is printed so that the test framework can capture and verify
 * an assertion failure is correctly triggered
 */
#	include <assert.h>
#	define CONTEND(COND) assert((" assertion failed " || 1) && (COND))



/* freestanding */
#else
#	define CONTEND(COND) ((COND)? (void) 0 : contend_fail())

#endif



#if defined(__cplusplus)
extern "C" {
#endif


/*
 * Assertion failure handler. Usually triggers core dump and resets the machine.
 * THE FUNCTION MUST NOT RETURN.
 */

#if __STDC_VERSION__ >= 201112L
/* noreturn keyword available since C11 */
#	include <stdnoreturn.h>
noreturn void contend_fail(void);



#elif defined(__GNUC__)
__attribute__ ((noreturn)) void contend_fail(void);



#else
#	warning Noreturn function needs inspection.
void contend_fail(void);
#endif



#if defined(__cplusplus)
}
#endif

#endif /* H30D103CF_33CB_472A_A14E_1FF09A1E0F2E */

