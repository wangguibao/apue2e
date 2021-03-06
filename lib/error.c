#include "apue.h"
#include <errno.h>
#include <stdarg.h>

/**
 * Print a message and return to caller. Caller specifies "errnoflag"
 */
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, ap);
    if (errnoflag) {
        snprintf(buf + strlen(buf), MAXLINE - strlen(buf),
                 ": %s", strerror(error));
    }

    strcat(buf, "\n");
    fflush(stdout);         /* In case stdout and stderr are same */
    fputs(buf, stderr);
    fflush(NULL);           /* flushes all stdio output streams */
}

/**
 * Fatal error related to a system call
 * Print a message and terminate
 */
void err_sys(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    exit(1);
}

/**
 * Fatal error unrelated to a system call
 * Print a message and terminate
 */
void err_quit(const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    err_doit(0, 0, fmt, ap);
    va_end(ap);
    exit(1);
}

/**
 * Fatal error related to a system call
 * Print a message, dump core, and terminate
 */
void err_dump(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
    abort();                            /* Dump core and terminate*/
    exit(1);                            /* Shouldn't get here */
}

/**
 * Nonfatal error related to a system call
 * Print a message and return
 */
void err_ret(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    err_doit(1, errno, fmt, ap);
    va_end(ap);
}

