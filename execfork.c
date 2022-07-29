#include "shell.h"

/**
 * execfork - executes a fork
 * @envp: environmental
 * @args: arguments
 * @name: program name
 */

void execfork(char **envp, char **args, char *name)
{
	pid_t cpid;
	int status;

	if (access(args[0], X_OK) != 0 || access(args[0], F_OK) != 0)
	{
		perror(name);
		return;
	}
	cpid = fork();

	if (cpid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			perror(name);
			_exit(0);
		}
	}
	wait(&status);
}
