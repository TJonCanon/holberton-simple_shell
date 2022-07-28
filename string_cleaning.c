#include "shell.h"

void countwords(char *buf, size_t *wc, const char dl, unsigned int *slen)
{
	int i = 0;

	if (!buf)
		exit(0);
	*wc = 0;
	if (*buf != '\0')
	{
		for (; buf[++i] != '\0';)
		{
		}

		for (*slen = i; --i >= 0;)
		{
			if (buf[i] != dl)
			{
				if (buf[i + 1] == dl || buf[i + 1] == '\0')
					(*wc)++;
			}
		}
	}
}

void squeeze_spaces(char *str_d)
{
	int i = 0, c = 0;

	for (; str_d[i]; i++)
	{
	}

	for (i--; i >= 0; i--)
	{
		if (str_d[i] == 32 && (str_d[i - 1] == 32 || str_d[i + 1] == 0 || i == 0))
			for (c = i; str_d[c]; c++)
			{
				str_d[c] = str_d[c + 1];
			}
	}
}
