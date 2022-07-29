#include "shell.h"

void dsh_exit(char *buf)
{
	free(buf);
	exit(0);
}
