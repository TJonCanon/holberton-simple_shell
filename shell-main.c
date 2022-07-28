#include "shell.h"

int main(int ac, char **av, char **envp)
{
	char *PS1 = "$ ", *buf = NULL,  *path = NULL;
	char **args = NULL, **pathsplit = NULL;
	int i = 0, c = 0, status, interactive = isatty(STDIN_FILENO);
	pid_t cpid;
	size_t wc = 0, pathc = 0;

	ignoreargs;

	do {
		if (interactive)
			printf("%s", PS1);
		dsh_read_line(&buf);
		strbrk(buf, &args, ' ', &wc);

		if (!args)
			goto fail;
		/* somehow we need to detect if a valid command is provided prior */
		/* to actually forking here. */

		if (access(args[0], F_OK) == 0)
		{
exec:                   cpid = fork();

			if (cpid == 0)
			{
				if (execve(args[0], args, envp) == -1)
					perror("Error");
				exit(0);
			}
			wait(&status);
		}
		else
		{
			path = getenv("PATH");
			strbrk(path, &pathsplit, ':', &pathc);
			for (i = 0; pathsplit[i] != NULL; i++)
			{
				_strcat(&pathsplit[i], args[0]);
				if (access(pathsplit[i], F_OK) == 0)
				{
					for (c = 0; pathsplit[i][c] != '\0'; c++)
					{
					}
					args[0] = realloc(args[0], ++c);
					_strcpy(&args[0], pathsplit[i]);
					goto exec;
				}
				free(pathsplit[i]);
			}
			free(pathsplit);
		}

fail:		freestuff(args, &wc, buf);

	} while (interactive);

	return (0);
}
