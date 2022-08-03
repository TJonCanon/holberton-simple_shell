#include "shell.h"

/**
 * dsh_exit - flushes streams, frees, and exits
 * @buf: string alloc'ed by dsh_readline
 */
void dsh_exit(char *buf, char ***paths, size_t *pathc)
{
	size_t i;

	fflush(NULL);

	free(buf);

	if (*pathc > 0)
	{
		for (i = 0; i < *pathc; i++)
		{
			free(paths[0][i]);
			paths[0][i] = NULL;
		}
		free(paths[0]);
		paths[0] = NULL;
		*pathc = 0;
	}
	exit(errno == 25 ? errno = 0 : errno);
}
