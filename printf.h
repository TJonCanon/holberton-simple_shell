#ifndef MAIN_H
#define MAIN_H

/* MACROS */
#include "printf_macros.h"

/* Standard Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
/* STRUCT */
/**
 * struct specifier - checks for valid format specifier from printf
 * @spec: character to match against input
 * @f: function pointer to output matching spec
 */
typedef struct specifier
{
	char *spec;
	int (*f)(va_list, char *);
} spec;
/* Old Function Prototypes*/
int _strlen(char *s);
/* New Function Prototypes */
/**
 * _printf - print formatted output
 * @format: format string to indicate type of variadic args
 * Return: Number of printed chars
 */
int _printf(const char *format, ...)
	__attribute__((__format__(printf, 1, 2)));
/* Subroutines */
int print_bighex(va_list args, char *bigbuf);
int print_bin(va_list args, char *bigbuf);
int print_char(va_list args, char *bigbuf);
int print_int(va_list args, char *bigbuf);
int print_oct(va_list args, char *bigbuf);
int print_percent(va_list args, char *bigbuf);
int print_realstring(va_list args, char *bigbuf);
int print_revstring(va_list args, char *bigbuf);
int print_rot13string(va_list args, char *bigbuf);
int print_smallhex(va_list args, char *bigbuf);
int print_string(va_list args, char *bigbuf);
int print_unsigned(va_list args, char *bigbuf);

int (*get_spec(char s))(va_list, char *);
char *convert(unsigned int num, int base);
#endif
