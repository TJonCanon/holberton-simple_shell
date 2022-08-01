#include "shell.h"
#include "printf.h"

/**
 * execfork - executes a fork
 * @ep: environmental
 * @as: arguments
 * @name: program name
 * @cc: command count from countcmd function
 * @ps: paths as double pointer element
 * @eno: error number
 */

void execfork(char **ep, char **as, char *name, size_t cc, char **ps, int *eno)
{
	pid_t cpid;
	int status;
	char *filepath = NULL;
	char *err = NULL;

	if (!as)
		return;

	if (cc > 1)
	{
		execmulti(as, ps, ep, name, eno);
		return;
	}

	if (access(as[0], F_OK))
		filepath = getcmd(ps, as[0]);
	else
		filepath = _strcat(&as[0], "");

	if (access(filepath, X_OK) != 0 || access(filepath, F_OK) != 0)
	{
		*eno = 127;
		err = errcat(name, filepath);
		write(2, err, _strlen(err));
		FREETWO(err, filepath);
		return;
	}
	cpid = fork();

	if (cpid == 0)
	{
		if (execve(filepath, as, ep) == -1)
		{
			_printf("%s: %d: %s", as[0], errno, filepath);
			perror(as[0]);
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
 * @eno: error number
 */

void execmulti(char **args, char **paths, char **envp, char *name, int *eno)
{
	char *filepath = NULL, *namein[2] = {NULL, NULL}, *err = NULL;
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
			*eno = 127;
			err = errcat(name, filepath);
			write(2, err, _strlen(err));
			FREETWO(err, filepath);
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

/**
 * errcat - writes sh-style error messages
 * @pname: argv[0] as invoked
 * @cname: user-provided input command
 * Return: sh-style error string
 */

char *errcat(char *pname, char *cname)
{
	int i, j;
	char *erract = malloc(256 * sizeof(char));
	char *errsuff = ": not found\n";
	char *errmid = ": 1: ";

	for (i = 0; pname[i]; i++)
		erract[i] = pname[i];
	for (j = 0; errmid[j]; j++)
		erract[i++] = errmid[j];
	for (j = 0; cname[j]; j++)
		erract[i++] = cname[j];
	for (j = 0; errsuff[j]; j++)
		erract[i++] = errsuff[j];
	erract[i] = '\0';

	return (erract);
}
