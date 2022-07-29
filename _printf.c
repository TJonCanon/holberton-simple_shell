#include "printf.h"

/**
  * _printf - print formatted output
  * @format: string to indicate formats to print
  * Return: Total chars printed, or -1 on fails
  */

int _printf(const char *format, ...)
{
	unsigned int c = 0; /* valid char count */
	char *bigbuf; /* buffer to write */
	va_list args; /* variadic args */
	int (*s)(va_list, char*); /* specifier function pointer */

	if (!format)
		return (-1);

	startprintf; /* va_start, calloc 2048B to write */

	for (; *format; format++)
	{
		if (*format == '%')
		{
			if (!*(format + 1))
			{
				write(1, bigbuf, c);
				return (-1);
			}
			s = get_spec(*++format);
			if (s)
				c += s(args, bigbuf);
			else
				writetwochars; /* save prev & curr char, c + 2 */
		}
		else
		{
			bigbuf[c] = *format;
			c++;
		}
	}

	endprintf; /* write buffer to stdout , va_end, free buffer */
	return (c);
}
