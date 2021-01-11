/*
 * POSIX Multi-threaded Logger
 */
#include <platform/posixos/logger.h>
#include <platform/contend.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include <stdarg.h>
#include <pthread.h>



/*
 * Shared logger state data, protected by mutex
 */
static struct
{
	pthread_mutex_t mutex;
	volatile int runtime_level;
	FILE *volatile log_file;
} _g_logger;



/*
 * Internal functions
 */
static const char* _stringify_level(int level);
static void _lock_logger(void);
static void _unlock_logger(void);



/*
 * Timestamp string buffer size
 */
#define STRFTIME_LENGTH   (30)



/*
 * External symbols
 */
void logger_begin(int runtime_level)
{
	_g_logger.runtime_level = runtime_level;

	/*
	 * Append to existing log file. If not found, create.
	 */
#if defined(CONFIG_LOGGER_PATH)
	_g_logger.log_file = fopen(CONFIG_LOGGER_PATH, "a");
#else
	_g_logger.log_file = stdout;
#endif

	pthread_mutex_init(&_g_logger.mutex, NULL);
}



void logger_finish(void)
{
	/*
	 * Destroying a locked mutex invokes undefined behavior. For fast mutexes, unlock can be called
	 * when the mutex is unlocked without causing an error.
	 */
	pthread_mutex_unlock(&_g_logger.mutex);
	pthread_mutex_destroy(&_g_logger.mutex);

#if defined(CONFIG_LOGGER_PATH)
	if (_g_logger.log_file != NULL)
		fclose(_g_logger.log_file);
#endif
}



void logger_backend(int level, const char *file, const char *func, int line,
	const char *format, ...)
{
	CONTEND(format != NULL);

	if (level >= _g_logger.runtime_level)
	{
		time_t now = time(NULL);
		CONTEND(now != (time_t) -1);

		struct tm *now_calendar = gmtime(&now);
		CONTEND(now_calendar != NULL);

		char time_string[STRFTIME_LENGTH];
		strftime(time_string, STRFTIME_LENGTH, "%Y-%m-%d %a %H:%M:%S", now_calendar);

		_lock_logger();
		CONTEND(_g_logger.log_file != NULL);

		fprintf(_g_logger.log_file, "\033[1;36m[%s]\033[0m[%5s] %s (%s:%d): ",
				time_string, _stringify_level(level), func, file, line);

		va_list args;
		va_start(args, format);
		vfprintf(_g_logger.log_file, format, args);
		va_end(args);

		fprintf(_g_logger.log_file, "\n");
		_unlock_logger();
	}
}



/*
 * Internal functions
 */
static const char* _stringify_level(int level)
{
	const char *ret = NULL;

	if (level == 0)
		ret = "\033[1mTRACE\033[0m";

	else if (level == 1)
		ret = "\033[1;36mDEBUG\033[0m";

	else if (level == 2)
		ret = "\033[1;34mINFO\033[0m";

	else if (level == 3)
		ret = "\033[1;33mWARN\033[0m";

	else if (level == 4)
		ret = "\033[1;91mERR\033[0m";

	else if (level == 5)
		ret = "\033[1;91mCRIT\033[0m";

	else {
		/* should not get here */
		CONTEND(0);
	}

	return ret;
}

static void _lock_logger(void)
{
	pthread_mutex_lock(&_g_logger.mutex);
}

static void _unlock_logger(void)
{
	pthread_mutex_unlock(&_g_logger.mutex);
}

