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
/* Printf Lib */
#include "printf.h"
/* Main Routines */
void dsh_read_line(char **buf, char *name);
void freestuff(char **args, size_t *wc, char *buf, char **path, size_t *pathc);
void strbrk(char *buf, char ***args, const char delim, size_t *wc, char *name);
void getcmd(char **args, char ***paths, size_t *pathc, char *name);
void execfork(char **envp, char **args, char *name);
/* Subroutines */
void countwords(char *buf, size_t *wc, const char dl, unsigned int *slen);
void squeeze_spaces(char *str_d, unsigned int *slen);
void _strcat(char **dest, char *src);
void _strcpy(char **dest, char *src);
int _strcmp(char *s1, char *s2);
void dsh_exit(char *buf);
/* Macros  */
#define ignoreargs do {				\
		((void) ac) ;			\
		((void) av);			\
	} while (0)
#endif /* SHELL */
