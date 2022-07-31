#include "shell.h"
#define doubleincrement(i, j) do { \
		i++; \
		j++; \
	} while (0)
/**
 * strbrk - takes one string and spits into a double pointer
 * @buf: buffer
 * @args: arguments
 * @delim: delimeter
 * @wc: Word count
 * Return - void
 */
void strbrk(char *buf, char ***args, const char delim, size_t *wc)
{
	unsigned int c, i, j = 0, slen = 0;
	short wordlen = 0;

	countwords(buf, wc, delim, &slen);

	if (delim == ' ')
		squeeze_spaces(buf, &slen);

	if (!buf || *buf == '\0' || *wc == 0)
		return;

	*args = malloc((*wc + 1) * sizeof(char *));

	if (!(*args))
		return;

	for (i = 0; i < slen; i++, wordlen++)
	{
		if (!buf[i + 1])
			wordlen++;

		if (buf[i] == delim || !buf[i + 1])
		{
			args[0][j] = malloc(++wordlen * sizeof(char));
			if (!args[0][j])
				return;
			wordlen = 0;
			doubleincrement(i, j);
		}
	}

	for (i = 0, j = 0; j < *wc; j++, i++)
	{
		for (c = 0; buf[i] && buf[i] != delim; c++, i++)
		{
			args[0][j][c] = buf[i];
		}
		args[0][j][c] = '\0';
	}
	args[0][j] = NULL;
}
