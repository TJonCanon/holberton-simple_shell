#include "printf.h"

/**
 * convert - converts numbers to strings in other bases
 * @num: number to convert to str
 * @base: number base to convert to
 * Return: string containing converted number
 */
char *convert(unsigned int num, int base)
{
	static const char Representation[] = "0123456789ABCDEF";
	static char buffer[33];
	char *ptr;

	ptr = &buffer[32];
	*ptr = '\0';

	do {
		*--ptr = Representation[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
/**
 * print_bin - prints input in base 2
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: # of chars written
 */
int print_bin(va_list args, char *bigbuf)
{
	char *num;
	int loc, len = 0;

	num = convert(va_arg(args, int), 2);

	loc = _strlen(bigbuf);

	writestrtobuf(num);

	return (len);
}
/**
 * print_oct - prints input in base 8
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: # of chars written
 */
int print_oct(va_list args, char *bigbuf)
{
	char *num;
	int loc, len = 0;

	num = convert(va_arg(args, int), 8);

	loc = _strlen(bigbuf);

	writestrtobuf(num);

	return (len);
}
/**
 * print_smallhex - prints input in base 16, with lowercase chars
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: # of chars written
 */
int print_smallhex(va_list args, char *bigbuf)
{
	char *num;
	int i, loc, len = 0;

	num = convert(va_arg(args, int), 16);

	for (i = 0; num[i]; i++)
	{
		if (num[i] >= 65)
			num[i] += 32; /* convert caps to lowercase */
	}

	loc = _strlen(bigbuf);

	writestrtobuf(num);

	return (len);
}
/**
 * print_bighex - prints input in base 16, with uppercase letters
 * @args: variadic list input
 * @bigbuf: destination string (2048)
 * Return: # of chars written
 */
int print_bighex(va_list args, char *bigbuf)
{
	char *num;
	int loc, len = 0;

	num = convert(va_arg(args, int), 16);

	loc = _strlen(bigbuf);

	writestrtobuf(num);

	return (len);
}
