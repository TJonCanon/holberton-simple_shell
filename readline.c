#include "shell.h"

void dsh_read_line(char **buf)
{
	char *newbuf;
	int bufsize = 128, pos = 0, c = 0;

	newbuf = calloc(bufsize, sizeof(char));

	if (!newbuf)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	*buf = newbuf;

	while ((c = getchar()) != EOF)
	{
		if (c != '\n')
		{
			(*buf)[pos] = c;
		}
		else
		{
			(*buf)[pos] = '\0';
			return;
		}
		pos++;

		if (pos >= bufsize)
		{
			bufsize += 128;
			*buf = realloc(*buf, bufsize);
			if (!buf)
			{
				perror("Error");
				exit(EXIT_FAILURE);
			}
		}
	}
	free(*buf);
	*buf = NULL;
}
