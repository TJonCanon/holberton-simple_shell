#include "printf.h"

/**
 * print_int - prints an input integer argument in base 10
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: number of chars printed
 */
int print_int(va_list args, char *bigbuf)
{
	int len = 0, loc, integer;
	char *num;

	v_init(integer, int); /* va_arg & loc = _strlen(bigbuf) */

	if (integer < 0)
	{
		if (integer != INT_MIN)
			integer = ABS(integer);
		bigbuf[loc] = '-';
		loc++;
		len++;
	}
	num = convert(integer, 10);

	writestrtobuf(num);

	return (len);
}

/**
  * print_unsigned - prints an input unsigned int arg in base 10
  * @args: variadic list input
  * @bigbuf: destination string (2048)
  * Return: number of chars printed
  */
int print_unsigned(va_list args, char *bigbuf)
{
	unsigned int len = 0, integer, loc;
	char *num;

	v_init(integer, unsigned int); /* va_arg & loc = _strlen(bigbuf) */

	num = convert(integer, 10);

	writestrtobuf(num);

	return (len);
}

/**
 * print_string - prints a string directly to stdout
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: number of chars printed
 */
int print_string(va_list args, char *bigbuf)
{
	char *s;
	int loc, len = 0;

	v_init(s, char *); /* va_arg & loc = _strlen(bigbuf) */

	if (!s)
		s = "(null)";

	writestrtobuf(s); /* copy all chars from string into buffer & count */

	return (len);
}

/**
 * print_char - take next argument as int, pass it to _putchar
 * @args: va_list argument
 * @bigbuf: destination string (2048)
 * Return: # of chars printed
 */
int print_char(va_list args, char *bigbuf)
{
	int _char, loc = 0;

	v_init(_char, int); /* va_arg & loc = _strlen(bigbuf) */

	bigbuf[loc] = _char;

	return (1);
}

/**
 * print_percent - adds a percent to bigbuf
 * @args: va_list (unused)
 * @bigbuf: string to write to
 * Return: always 1
 */

int print_percent(va_list args, char *bigbuf)
{
	int loc = 0;
	(void)args;

	loc = _strlen(bigbuf);

	bigbuf[loc] = '%';

	return (1);
}
