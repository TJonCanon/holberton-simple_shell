#include "shell.h"

void execfork(char **envp, char **args)
{
	pid_t cpid;
	int status;

	if (access(args[0], X_OK) != 0)
	{
		perror("Error");
		return;
	}
	cpid = fork();

	if (cpid == 0)
	{
		if (execve(args[0], args, envp) == -1)
			/* perror("Error"); */
			exit(0);
	}
	wait(&status);
}
