#include "shell.h"

void countwords(char *buf, int *wc);

int main(int ac, char **av)
{
	char *PS1 = "$ ", *buf = NULL, **split = NULL;
	pid_t cpid;
	int status;
	int wc = 0;
	(void) ac;
	(void) av;

	while (1)
	{
		printf("%s", PS1);

		dsh_read_line(&buf);

		countwords(buf, &wc);

		split = strbrk(buf, ' ', &wc);

		if (!split)
			goto fail;
		/* somehow we need to detect if a valid command is provided prior */
		/* to actually forking here. */

		cpid = fork();

		if (cpid == 0)
		{
			if (execve(split[0], split, NULL) == -1)
				perror("Error");
			exit(0);
		}
		wait(&status);
fail:		freestuff(split, &wc, buf);
	}
	return (0);
}

void countwords(char *buf, int *wc)
{
	int i;

	if (!buf)
		exit(0);
	if (*buf == '\0')
	{
		*wc = 0;
		return;
	}

	for (i = 0; buf[i] != '\0'; i++)
	{
	}

	for (*wc = 0; buf[--i];)
	{
		if (buf[i] != 32 && (buf[i - 1] == 32 || buf[i - 1] == '\0'))
			(*wc)++;
	}
}
