/***************************************************************************************************
 * Endianness Test
 *
 * Provides macros to test target platform endianness.
 *
 * Most Common:
 * ------------
 *
 * When CONFIG_ENDIAN == ENDIAN_BIG
 *    0xAABB       is stored as: 0xAA 0xBB
 *    0xAABBCCDD   is stored as: 0xAA 0xBB 0xCC 0xDD
 *
 * When CONFIG_ENDIAN == ENDIAN_LITTLE
 *    0xAABB       is stored as: 0xBB 0xAA
 *    0xAABBCCDD   is stored as: 0xDD 0xCC 0xBB 0xAA
 *
 *
 * Rare cases:
 * -----------
 *
 * When CONFIG_ENDIAN == ENDIAN_PDP
 *    0xAABB       is stored as: 0xAA 0xBB
 *    0xAABBCCDD   is stored as: 0xBB 0xAA 0xDD 0xCC
 *
 * When CONFIG_ENDIAN == ENDIAN_HS316
 *    0xAABB       is stored as: 0xBB 0xAA
 *    0xAABBCCDD   is stored as: 0xCC 0xDD 0xAA 0xBB
 **************************************************************************************************/
#ifndef H933FCD63_30B4_4449_9656_8D43FB157417
#define H933FCD63_30B4_4449_9656_8D43FB157417


/*
 * Macro CONFIG_ENDIAN is set to one of the following
 */
#define ENDIAN_BIG       (1)
#define ENDIAN_LITTLE    (2)
#define ENDIAN_PDP       (3)
#define ENDIAN_HS316     (4)



/*
 * GCC provides predefined macros to automatically detect endianness.
 * Here a wrapper is wrapped around it to make it consistent with the syntax used in this
 * header.
 */
#if defined(__GNUC__)
#	if !defined(CONFIG_ENDIAN)
#		if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#			define CONFIG_ENDIAN ENDIAN_LITTLE
#		elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#			define CONFIG_ENDIAN ENDIAN_BIG
#		elif __BYTE_ORDER__ == __ORDER_PDP_ENDIAN__
#			define CONFIG_ENDIAN ENDIAN_PDP
#		else
#			error "Endianness unknown."
#		endif
#	endif



/*
 * Unsupported compiler. Expect endianness to be manually defined from command line.
 */
#else
#	if !defined(CONFIG_ENDIAN)
#		error "Endianness unknown."
#	endif
#endif



#endif /* H933FCD63_30B4_4449_9656_8D43FB157417 */
