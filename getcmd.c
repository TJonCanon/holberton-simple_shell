#include "shell.h"
#define _strlen(str, len) for (len = 0; str[len] != '\0'; len++)
/**
 * getcmd - gathers commands
 * @args: arguments
 * @envp: environmental
 * @pathsplit: path split
 * @pathc: pathc
 * Return - void
 */
void getcmd(char **args, char **envp, char ***pathsplit, size_t *pathc)
{
	char *path;
	int  i = 0, c = 0;

	if (!args)
		return;
	if (access(args[0], F_OK) != 0)
	{
		path = getenv("PATH");
		strbrk(path, paths, ':', pathc, name);
		for (i = 0; paths[0][i] != NULL; i++)
		{
			_strcat(&paths[0][i], args[0]);
			if (access(paths[0][i], F_OK) == 0)
			{
				_strlen(paths[0][i], c);

				args[0] = realloc(args[0], ++c);

				_strcpy(&args[0], paths[0][i]);
			}
		}
	}
}
