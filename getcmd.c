#include "shell.h"
/**
 * countcmd - gets count of valid input commands
 * @args: arguments
 * @paths: pointer to store each path element
 * @cmdc: pointer to valid command count
 */
void countcmd(char **args, char **paths, size_t *cmdc)
{
	int  i, j;
	char *name = NULL;
	struct stat sb;

	*cmdc = 0;
	if (!args || !getenv("PATH") || *getenv("PATH") == '\0')
		return;
	for (j = 0; args[j]; j++)
	{
		if (access(args[j], F_OK) != 0)
		{
			for (i = 0; paths[i] != NULL; i++)
			{
				if (name)
					free(name);
				name = _strcat(&paths[i], args[j]);
				if (!access(name, F_OK))
				{
					free(name);
					name = NULL;
					(*cmdc)++;
					break;
				}
			}
		}
		else
			if (stat(args[j], &sb) == 0 && !S_ISDIR(sb.st_mode))
				(*cmdc)++;
	}
	if (name)
	{
		free(name);
		name = NULL;
	}
}
/**
 * getcmd - checks an input string and returns a valid command, if it exists
 * @paths: every folder from PATH variable
 * @cmd: input string to check as command
 * Return: pointer to command, whether it exists or not
 */
char *getcmd(char **paths, char *cmd)
{
	int i;
	char *newcmd = NULL;

	if (!paths)
		return (_strcat(&cmd, ""));

	if (access(cmd, F_OK) != 0)
	{
		for (i = 0; paths[i] != NULL; i++)
		{
			if (newcmd)
				free(newcmd);
			newcmd = _strcat(&paths[i], cmd);
			if (!access(newcmd, F_OK))
				break;
		}
	}
	if (access(newcmd, F_OK))
	{
		free(newcmd);
		return (_strcat(&cmd, ""));
	}

	return (newcmd);
}
