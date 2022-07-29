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

void squeeze_spaces(char *str_d, unsigned int *slen)
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

void _strcat(char **dest, char *src)
{
	int dn, sn;

	for (dn = 0 ; dest[0][dn] != '\0' ; dn++)
	{
	}
	for (sn = 0 ; src[sn] != '\0' ; sn++)
	{
	}
	dest[0] = realloc(dest[0], (dn + ++sn) + 1);

	dest[0][dn++] = '/';
	for (sn = 0 ; src[sn] != '\0' ; sn++, dn++)
	{
		dest[0][dn] = src[sn];
	}
	dest[0][dn] = '\0';
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

	for (i = 0 ; s1[i] != '\0' ; i++)
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
	}
	return (diff);
}
