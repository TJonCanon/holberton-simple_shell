#include "shell.h"

/**
 * dsh_exit - flushes streams, frees, and exits
 * @buf: string alloc'ed by dsh_readline
 */
void dsh_exit(char *buf)
{
	/* fflush(NULL); */
	free(buf);
	exit(errno);
}
