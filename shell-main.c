#include "shell.h"

int main(int ac, char **av, char **envp)
{
	char *PS1 = "$ ", *buf = NULL, **args = NULL;
	pid_t cpid;
	int status;
	int wc = 0;
	(void) ac;
	(void) envp;

	while (1)
	{
		args = av + 1;
		printf("%s", PS1);

		if (!*args)
		{
		dsh_read_line(&buf);
		args = strbrk(buf, ' ', &wc);
		}
		else
			args += ac;

		if (!*args)
			goto fail;
		/* somehow we need to detect if a valid command is provided prior */
		/* to actually forking here. */

		cpid = fork();

		if (cpid == 0)
		{
			if (execve(args[0], args, NULL) == -1)
				perror("Error");
			exit(0);
		}
		wait(&status);
fail:		freestuff(args, &wc, buf);
	}
	return (0);
}
