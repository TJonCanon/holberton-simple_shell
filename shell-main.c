#include "shell.h"
void getcmd(char **args, char **envp, char ***pathsplit, size_t *pathc);
void execfork(char **envp, char **args);

int main(int ac, char **av, char **envp)
{
	char *PS1 = "$ ", *buf = NULL, **pathsplit = NULL;
	char **args = NULL;
	int interactive = isatty(STDIN_FILENO);
	size_t wc = 0, pathc = 0;

	ignoreargs;

	do {
		if (interactive)
			printf("%s", PS1);
		dsh_read_line(&buf);

		strbrk(buf, &args, ' ', &wc);

		getcmd(args, envp, &pathsplit, &pathc);

		freestuff(args, &wc, buf, pathsplit, &pathc);

	} while (interactive);

	return (0);
}
void getcmd(char **args, char **envp, char ***pathsplit, size_t *pathc)
{
	char *path;
	int  i = 0, c = 0;

	if (!args)
		return;
	if (access(args[0], F_OK) != 0)
	{
		path = getenv("PATH");
		strbrk(path, pathsplit, ':', pathc);
		for (i = 0; pathsplit[0][i] != NULL; i++)
		{
			_strcat(&pathsplit[0][i], args[0]);
			if (access(pathsplit[0][i], F_OK) == 0)
			{
				for (c = 0; pathsplit[0][i][c] != '\0'; c++)
				{
				}
				args[0] = realloc(args[0], ++c);
				_strcpy(&args[0], pathsplit[0][i]);
				execfork(envp, args);
				return;
			}
		}
		perror("Error");
	}
}
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
