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
		{
			free(args[0][i]);
			args[0][i] = NULL;
		}
		free(args[0]);
		args[0] = NULL;
	}
	if (*pc > 0)
	{
		for (i = 0; i < *pc; i++)
		{
			free(ps[0][i]);
			ps[0][i] = NULL;
		}
		free(ps[0]);
		ps[0] = NULL;
		*pc = 0;
	}
}
