#include "shell.h"
/**
 * freestuff - frees data structures used by shell
 * @args: arguments
 * @wc: word count
 * @buf: buffer
 * @paths: path 1
 * @pathc: path 2
 * Return - void
 */
void freestuff(char **args, size_t *wc, char *buf, char **paths, size_t *pathc)
{
	unsigned int i;

	if (buf)
		free(buf);

	if (*wc > 0)
	{
		for (i = 0; i < *wc; i++)
		{
			free(args[i]);
			args[i] = NULL;
		}
		free(args);
		args = NULL;
	}
	if (*pathc > 0)
	{
		for (i = 0; i < *pathc; i++)
		{
			free(paths[i]);
			paths[i] = NULL;
		}
		free(paths);
		paths = NULL;
	}
}
