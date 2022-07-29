#include "shell.h"

void freestuff(char **args, size_t *wc, char *buf, char **path, size_t *pathc)
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
			free(path[i]);
			path[i] = NULL;
		}
		free(path);
		path = NULL;
	}
}
