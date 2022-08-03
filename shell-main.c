#include "shell.h"
#include "printf.h"
/**
 * main - runs the simple shell
 * @ac: argc
 * @av: argv
 * @envp: environmental
 * Return: 0
 */

int main(__attribute__ ((unused)) int ac, char **av, char **envp)
{
	char *PS1 = "($) ", **args = NULL, *buf = NULL, **paths = NULL;
	int i, dsh_errno = 0, interactive = isatty(STDIN_FILENO);
	size_t wc = 0, pathc = 0, cmdc = 0;
	int returnerr = 0;

	strbrk(getenv("PATH"), &paths, ':', &pathc); /* Split paths into a sentence*/

	do {
		if (interactive)
			_printf("%s @ %s %s", getenv("USER"), getenv("PWD"), PS1);
		dsh_read_line(&buf); /* Read user input, buf is NULL on EOF */

		if (buf && *buf) /* Not EOF or newline */
		{
			if (_strcmp("exit", buf) == 0)
			{
				dsh_exit(buf, &paths, &pathc);
			}
			if (_strcmp("env", buf) == 0)
			{
				for (i = 0; envp[i]; i++)
					_printf("%s\n", envp[i]);
				free(buf);
				continue;
			}
		}
		strbrk(buf, &args, ' ', &wc); /* Split buf into a sentence */
/* Count number of commands */
		countcmd(args, paths, &cmdc, &returnerr, &buf);
/* Handles execution and translation */
		execfork(envp, args, av[0], cmdc, paths, &dsh_errno);
/* Free all objects */
		freestuff(&args, &wc, buf, &paths, &pathc);

	} while (interactive && buf); /* terminate if noninteractive or EOF */

	if (((returnerr) && errno == 2) || errno == 127)
		dsh_errno = errno;
	return (dsh_errno); /* Return errors 127 or 2 (Needs work) */
}
