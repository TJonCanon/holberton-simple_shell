#ifndef SHELL
#define SHELL
/* Standard Library */
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/* Function Prototypes */
char **strbrk(char *str, const char delim, unsigned int *wc);
void freestuff(char **split, unsigned int *wc, char *buf);
void dsh_read_line(char **buf);
/* Globals */
#endif /* SHELL */
