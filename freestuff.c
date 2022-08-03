#include "shell.h"
/**
 * freestuff - frees data structures used by shell
 * @args: user input as double pointer
 * @wc: num of elements in args
 * @buf: user input from last run
 * @ps: path list as double pointer
 * @pc: path element count
 */
void freestuff(char ***args, size_t *wc, char *buf, char ***ps, size_t *pc)
{
	unsigned int i;

	if (buf)
		free(buf);

	if (*wc > 0)
	{
		for (i = 0; i < *wc; i++)
			nullify(args[0][i]);
		nullify(args[0]);
	}

	if (!buf && *pc > 0)
	{
		for (i = 0; i < *pc; i++)
			nullify(ps[0][i]);
		nullify(ps[0]);
		*pc = 0;
	}
}
