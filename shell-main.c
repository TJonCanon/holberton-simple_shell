#include "shell.h"
/**
 * main - runs the simple shell
 * @ac: argc
 * @av: argv
 * @envp: environmental
 * Return: 0
 */

int main(int ac, char **av, char **envp)
{
	char *PS1 = "($) ", *buf = NULL, **pathsplit = NULL;
	char **args = NULL;
	int interactive = isatty(STDIN_FILENO), i;
	size_t wc = 0, pathc = 0;

	(void) ac;

	do {
		if (interactive)
			_printf("%s @ %s %s", getenv("USER"), getenv("PWD"), PS1);
		dsh_read_line(&buf, av[0]);

		if (buf)
		{
			if (_strcmp(buf, "exit") == 0)
			{
				dsh_exit(buf);
			}
			if (_strcmp(buf, "env") == 0)
			{
				for (i = 0; envp[i]; i++)
					_printf("%s\n", envp[i]);
				free(buf);
				continue;
			}
		}
		strbrk(buf, &args, ' ', &wc, av[0]);

		getcmd(args, &pathsplit, &pathc, av[0]);

		execfork(envp, args, av[0]);

		freestuff(args, &wc, buf, pathsplit, &pathc);

	} while (interactive);

	return (0);
}
