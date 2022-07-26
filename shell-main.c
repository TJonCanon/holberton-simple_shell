#include "shell.h"

int main(int ac, char **av, char **envp)
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

		split = strbrk(buf, ' ', &wc);

		if (!split)
			goto fail;
		/* somehow we need to detect if a valid command is provided prior */
		/* to actually forking here. */

		cpid = fork();

		if (cpid == 0)
		{
			if (execve(split[0], split, envp) == -1)
				perror("Error");
			exit(0);
		}
		wait(&status);
fail:		freestuff(split, &wc, buf);
	}
	return (0);
}
