#include "shell.h"

char *lsh_read_line(void)
{
	int bufsize = 128, pos = 0, c = 0;
	char *buf;

	buf = calloc(bufsize, sizeof(char));

	if (!buf)
	{
		perror("Agh! Bad allocation!\n");
		exit(EXIT_FAILURE);
	}

	while ((c = getchar()))
	{
		if (c == EOF || c == '\n')
		{
			buf[pos] = '\0';
			return (buf);
		}
		else
		{
			buf[pos] = c;
		}
		pos++;

		if (pos >= bufsize)
		{
			bufsize += 128;
			buf = realloc(buf, bufsize);
			if (!buf)
			{
				perror("Agh! Bad allocation!\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	return (NULL);
}
