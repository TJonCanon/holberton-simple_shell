#ifndef SHELL
#define SHELL
/* Standard Library */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
/* Main Routines */
void dsh_read_line(char **buf);
void freestuff(char **split, size_t *wc, char *buf);
void strbrk(char *buf, char ***args, const char delim, size_t *wc);
/* Subroutines */
void countwords(char *buf, size_t *wc, const char dl);
void squeeze_spaces(char *str_d);
/* Macros  */
#define ignoreargs do {				\
		((void) ac) ;			\
		((void) av);			\
	} while (0)
#endif /* SHELL */
