#include "shell.h"

char **strbrk(char *str, const char delim, unsigned int *wc)
{
	unsigned int c, i, j = 0;
	short wordlen = 0;
	char **words;

	if (!str)
	{
		write(2, "Bad String Input\n", 17);
		return (NULL);
	}
	for (i = 0, *wc = 1; str[i]; i++)
	{
		if (str[i] == delim)
			*wc += 1;
	}

	words = calloc((*wc + 1), sizeof(char *));

	if (!(words))
		return (NULL);

	for (i = 0; str[i]; i++, wordlen++)
	{
		if (str[i] == delim || !str[i + 1])
		{
			words[j] = calloc(++wordlen, sizeof(char));
			wordlen = 0;
			++i;
			++j;
		}
	}

	for (i = 0, j = 0; j < *wc; j++, i++)
	{
		for (c = 0; str[i] && str[i] != delim; c++, i++)
		{
			words[j][c] = str[i];
		}
	}
	return (words);
}
