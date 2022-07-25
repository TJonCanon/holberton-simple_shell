#include "shell.h"

char **strbrk(char *buf, const char delim, int *wc)
{
	int c, i, j = 0;
	short wordlen = 0;
	char **words;

	if (*buf == '\0' || *wc == 0)
		return (NULL);

	words = calloc((*wc + 1), sizeof(char *));

	if (!(words))
		return (NULL);

	for (i = 0; buf[i]; i++, wordlen++)
	{
		if (buf[i] == delim || !buf[i + 1])
		{
			words[j] = calloc(++wordlen, sizeof(char));
			wordlen = 0;
			++i;
			++j;
		}
	}

	for (i = 0, j = 0; j < *wc; j++, i++)
	{
		for (c = 0; buf[i] && buf[i] != delim; c++, i++)
		{
			words[j][c] = buf[i];
		}
	}
	return (words);
}
