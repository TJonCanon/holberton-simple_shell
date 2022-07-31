#include "shell.h"

/**
 * dsh_read_line - reads line
 * @buf: buffer
 * @name: program name
 */
void dsh_read_line(char **buf, char *name)
{
	char *newbuf = NULL;
	size_t bufsize = 128, pos = 0;
	int c = 0;

	newbuf = malloc(bufsize * sizeof(char));

	if (!newbuf)
		return;

	*buf = newbuf;

	while ((c = getc(stdin)) != EOF)
	{
		if (c == '\n')
		{
			if (!isatty(STDIN_FILENO))
				continue;
			else
			{
				(*buf)[pos] = '\0';
				break;
			}
		}
		(*buf)[pos++] = c;

		if (pos >= bufsize)
		{
			*buf = realloc(*buf, bufsize *= 2);
			if (!buf)
			{
				perror(name);
				exit(EXIT_FAILURE);
			}
		}
	}
	if (c == -1 && isatty(STDIN_FILENO))
	{
		free(*buf);
		*buf = NULL;
	}
}
