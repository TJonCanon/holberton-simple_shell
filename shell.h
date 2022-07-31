#ifndef SHELL
#define SHELL
/* Standard Library */
#include <ctype.h>
#include <errno.h>
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
void freestuff(char ***args, size_t *wc, char *buf, char ***ps, size_t *pc);
void strbrk(char *buf, char ***args, const char delim, size_t *wc);
void countcmd(char **args, char **paths, size_t *pathc, bool *err);
void execfork(char **envp, char **args, char *name, size_t cmdc, char **paths);
/* Subroutines */
void countwords(char *buf, size_t *wc, const char dl, unsigned int *slen);
void squeeze_spaces(char *str_d, unsigned int *slen);
void execmulti(char **args, char **paths, char **envp, char *name);
char *getcmd(char **paths, char *cmd);
char *_strcat(char **dest, char *src);
void _strcpy(char **dest, char *src);
int _strcmp(char *s1, char *s2);
void dsh_exit(char *buf);
/* Macros  */
#define _strlen_(str, len) for (len = 0; str[len] != '\0'; len++)
#define nullify(arg) do {			\
		free(arg);			\
		arg = NULL;			\
	} while (0)
#endif /* SHELL */
