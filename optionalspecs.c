#include "printf.h"
/**
 * print_realstring - prints a string directly to stdout
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: number of chars printed
 */
int print_realstring(va_list args, char *bigbuf)
{
	char *s, *invalid;
	int len = 0, loc;

	v_init(s, char *); /* va_arg + strlen(bigbuf) */

	if (!s)
		s = "(null)";


	for (len = 0; *s ; s++)
	{
		if (*s < 32 || *s > 126)
		{
			bigbuf[loc] = '\\';
			bigbuf[loc + 1] = 'x';

			invalid = convert(*s, 16);

			if (_strlen(invalid) < 2)
			{
				bigbuf[loc + 2] = '0';
				loc++;
				len++;
			}

			for (loc += 2, len += 2; *invalid ; invalid++, loc++, len++)
			{
				bigbuf[loc] = *invalid;
			}
			continue;
		}
		bigbuf[loc] = *s;
		len++;
		loc++;
	}

	return (len);
}
