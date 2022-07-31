#include "shell.h"
#include "printf.h"

/**
 * execfork - executes a fork
 * @envp: environmental
 * @args: arguments
 * @name: program name
 * @cmdc: command count from countcmd function
 * @paths: paths as double pointer element
 */

void execfork(char **envp, char **args, char *name, size_t cmdc, char **paths)
{
	pid_t cpid;
	int status;
	char *filepath = NULL, *temp = NULL;

	(void) filepath;
	(void) temp;

	if (!args)
		return;

	if (cmdc > 1)
	{
		execmulti(args, paths, envp, name);
		return;
	}

	if (access(args[0], F_OK))
		filepath = getcmd(paths, args[0]);
	else
		filepath = _strcat(&args[0], "");

	if (access(filepath, X_OK) != 0 || access(filepath, F_OK) != 0)
	{
		perror(name);/* _printf("%s: 1: %s: not found\n", name, filepath); */
		free(filepath);
		return;
	}
	cpid = fork();

	if (cpid == 0)
	{
		if (execve(filepath, args, envp) == -1)
		{
			_printf("%s: %d: %s", args[0], errno, filepath);
			perror(NULL);
		}
		_exit(0);
	}
	wait(&status);
	free(filepath);
}
/**
 * execmulti - in case of multiple comands being given, this execs them.
 * @args: user input as double pointer
 * @paths: every folder from PATH variable
 * @envp: environment variables
 * @name: program name as invoked (av[0])
 */

void execmulti(char **args, char **paths, char **envp, char *name)
{
	char *filepath = NULL, *namein[2] = {NULL, NULL};
	int i, status;
	pid_t cpid;

	namein[0] = name;
	for (i = 0; args[i]; i++)
	{
		if (access(args[i], F_OK) != 0)
			filepath = getcmd(paths, args[i]);
		else
			filepath = _strcat(&args[i], "");

		if (access(filepath, X_OK) != 0 || access(filepath, F_OK) != 0)
		{
			_printf("%s: 1: %s: not found\n", name, filepath);
			free(filepath);
			continue;
		}
		cpid = fork();
		if (cpid == 0)
		{
			if (execve(filepath, namein, envp) == -1)
			{
				perror(name);
			}

			_exit(0);
		}
		wait(&status);
		free(filepath);
	}
}
