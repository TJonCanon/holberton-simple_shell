#include "shell.h"

void dsh_exit(char *buf)
{
	fflush(NULL);
	free(buf);
	exit(0);
}
