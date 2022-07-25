#include "shell.h"

int main(int ac, char **av)
{
	char *PS1 = "$ ", *buf = NULL, **split = NULL;
	pid_t cpid;
	int status;
	unsigned int wc = 0;
	(void) ac;
	(void) av;

	do {
		freestuff(split, &wc, buf);

		printf("%s", PS1);

		dsh_read_line(&buf);
		if (!buf)
			break;
		if (*buf == '\0')
			continue;

		split = strbrk(buf, ' ', &wc);

		if (!split)
			continue;
		/* somehow we need to detect if a valid command is provided prior */
		/* to actually forking here. */

		cpid = fork();

		if (cpid != 0)
		{
			wait(&status);
			continue;
		}
		buf = NULL;
		if (execve(split[0], split, NULL) == -1)
			perror("Error");
	} while (buf);
	return (0);
}

void freestuff(char **split, unsigned int *wc, char *buf)
{
	unsigned int i;

	if (buf)
		free(buf);

	if (split)
	{
		for (i = 0; i < *wc; i++)
		{
			free(split[i]);
		}
		free(split);
	}
}
