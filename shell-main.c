#include "shell.h"
#include "printf.h"
/**
 * main - runs the simple shell
 * @ac: argc
 * @av: argv
 * @envp: environmental
 * Return: 0
 */

int main(int ac, char **av, char **envp)
{
	char *PS1 = "($) ", *buf = NULL, **paths = NULL;
	char **args = NULL;
	int i, dsh_errno = 0, interactive = isatty(STDIN_FILENO);
	size_t wc = 0, pathc = 0, cmdc = 0;
	bool returnerr = false;
	(void) ac;

	do {
		if (interactive)
			_printf("%s @ %s %s", getenv("USER"), getenv("PWD"), PS1);
		dsh_read_line(&buf);

		if (buf && *buf)
		{
			if (_strcmp("exit", buf) == 0)
			{
				dsh_exit(buf);
			}
			if (_strcmp("env", buf) == 0)
			{
				for (i = 0; envp[i]; i++)
					_printf("%s\n", envp[i]);
				free(buf);
				continue;
			}
		}
		strbrk(buf, &args, ' ', &wc);
		strbrk(getenv("PATH"), &paths, ':', &pathc);

		countcmd(args, paths, &cmdc, &returnerr);

		execfork(envp, args, av[0], cmdc, paths);

		freestuff(&args, &wc, buf, &paths, &pathc);

	} while (interactive);

	if (returnerr && errno != 25 && errno != 0)
		dsh_errno = errno;
	return (dsh_errno); /* may have unintended consequences */
}
