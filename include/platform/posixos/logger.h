/*
 * POSIX Multi-threaded Logger
 */
#ifndef H7ED8498A_A1DE_408F_A79C_21DF005E1B58
#define H7ED8498A_A1DE_408F_A79C_21DF005E1B58

#if CONFIG_LOGGER_LEVELTRACE
#	define LOGGER_TRACE(...) logger_backend(0, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_DEBUG(...) logger_backend(1, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_INFO(...)  logger_backend(2, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_WARN(...)  logger_backend(3, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_ERR(...)   logger_backend(4, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#elif CONFIG_LOGGER_LEVELDEBUG
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) logger_backend(1, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_INFO(...)  logger_backend(2, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_WARN(...)  logger_backend(3, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_ERR(...)   logger_backend(4, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#elif CONFIG_LOGGER_LEVELINFO
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) ((void) 0)
#	define LOGGER_INFO(...)  logger_backend(2, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_WARN(...)  logger_backend(3, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_ERR(...)   logger_backend(4, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#elif CONFIG_LOGGER_LEVELWARN
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) ((void) 0)
#	define LOGGER_INFO(...)  ((void) 0)
#	define LOGGER_WARN(...)  logger_backend(3, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_ERR(...)   logger_backend(4, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#elif CONFIG_LOGGER_LEVELERR
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) ((void) 0)
#	define LOGGER_INFO(...)  ((void) 0)
#	define LOGGER_WARN(...)  ((void) 0)
#	define LOGGER_ERR(...)   logger_backend(4, __FILE__, __func__, __LINE__, __VA_ARGS__)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#elif CONFIG_LOGGER_LEVELCRIT
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) ((void) 0)
#	define LOGGER_INFO(...)  ((void) 0)
#	define LOGGER_WARN(...)  ((void) 0)
#	define LOGGER_ERR(...)   ((void) 0)
#	define LOGGER_CRIT(...)  logger_backend(5, __FILE__, __func__, __LINE__, __VA_ARGS__)

#else
#	define LOGGER_TRACE(...) ((void) 0)
#	define LOGGER_DEBUG(...) ((void) 0)
#	define LOGGER_INFO(...)  ((void) 0)
#	define LOGGER_WARN(...)  ((void) 0)
#	define LOGGER_ERR(...)   ((void) 0)
#	define LOGGER_CRIT(...)  ((void) 0)
#endif



#if defined(__cplusplus)
extern "C" {
#endif

void logger_begin(int runtime_level);
void logger_finish(void);
void logger_backend(int level, const char *file, const char *func, int line,
	const char *format, ...);

#if defined(__cplusplus)
}
#endif

#endif /* H7ED8498A_A1DE_408F_A79C_21DF005E1B58 */
