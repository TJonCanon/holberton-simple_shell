#include "shell.h"

void strbrk(char *buf, char ***args, const char delim, size_t *wc)
{
	unsigned int c, i, j = 0, slen = 0;
	short wordlen = 0;

	countwords(buf, wc, delim, &slen);

	if (delim == ' ')
		squeeze_spaces(buf, &slen);

	if (*buf == '\0' || *wc == 0)
		return;

	*args = calloc((*wc + 1), sizeof(char *));

	if (!(*args))
		return;

	for (i = 0; i < slen; i++, wordlen++)
	{
		if (!buf[i + 1])
			wordlen++;
		if (buf[i] == delim || !buf[i + 1])
		{
			args[0][j] = calloc(++wordlen, sizeof(char));
			wordlen = 0;
			++i;
			++j;
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
