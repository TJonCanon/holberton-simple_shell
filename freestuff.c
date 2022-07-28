#include "shell.h"

void freestuff(char **split, size_t *wc, char *buf)
{
	unsigned int i;

	if (buf)
		free(buf);

	if (*wc > 0)
	{
		for (i = 0; i < *wc; i++)
		{
			free(split[i]);
			split[i] = NULL;
		}
		free(split);
		split = NULL;
	}
}
