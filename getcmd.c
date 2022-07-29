#include "shell.h"

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
