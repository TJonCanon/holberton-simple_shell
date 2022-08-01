#include "shell.h"
/**
 * countwords - counts number of words
 * @buf: buffer
 * @wc: word count
 * @dl: delimiter
 * @slen: string length
 * return - void
 */
void countwords(char *buf, size_t *wc, const char dl, unsigned int *slen)
{
	int i = 0;

	*wc = 0;

	if (!buf)
		return;

	if (*buf != '\0')
	{
		for (; buf[++i] != '\0';)
		;

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
/**
 * squeeze_spaces - squeeze spaces
 * @str_d: string to clean
 * @slen: string length after clenaing
 */
void squeeze_spaces(char *str_d, unsigned int *slen)
{
	int i = 0, c = 0;

	for (; str_d[i]; i++)
	{
		if (str_d[i] == '\n')
			str_d[i] = ' ';
	}

	for (i--; i >= 0; i--)
	{
		if (str_d[i] == 32 && (i == 0 || str_d[i - 1] == 32 || str_d[i + 1] == 0))
			for (c = i; str_d[c]; c++)
			{
				str_d[c] = str_d[c + 1];
			}
	}
	for (*slen = 0; str_d[*slen]; (*slen)++)
	{
	}
}

/**
 * _strcat - Concatenates two strings
 * @dest: destination string
 * @src: string to be appended to dest
 * Return: pointer to destination string
 */

char *_strcat(char **dest, char *src)
{
	char *new;
	int dn = 0, sn;

	if (dest[0])
		_strlen_(dest[0], dn);
	_strlen_(src, sn);

	new = malloc(((dn + ++sn) + 1) * sizeof(char));

	if (dest[0])
	{
		for (dn = 0; dest[0][dn]; dn++)
			new[dn] = dest[0][dn];
		if (sn > 2)
			new[dn++] = '/';
	}
	for (sn = 0 ; src[sn] != '\0' ; sn++, dn++)
		new[dn] = src[sn];

	new[dn] = '\0';

	return (new);
}

/**
 * _strcpy - copies one string to another location
 * Return: pointer to destination string
 * @dest: location to copy to
 * @src: string to be copied
 */

void _strcpy(char **dest, char *src)
{
	int c;

	for (c = 0; src[c]; c++)
	{
		dest[0][c] = src[c];
	}
	dest[0][c] = '\0';
}

/**
 * _strcmp - compare two strings via ascii values
 * @s1: string 1 to compare
 * @s2: string 2 to compare
 * Return: difference between strings
 */

int _strcmp(char *s1, char *s2)
{
	int i;
	int diff = 0;

	for (i = 0 ; s1[i] && s2[i]; i++)
	{
		if (s1[i] != s2[i])
			diff = i;
	}
	return (diff);
}
