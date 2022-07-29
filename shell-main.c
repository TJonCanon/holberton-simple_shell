#include "shell.h"

int main(int ac, char **av, char **envp)
{
	char *PS1 = "($) ", *buf = NULL, **pathsplit = NULL;
	char **args = NULL;
	int interactive = isatty(STDIN_FILENO);
	size_t wc = 0, pathc = 0;

	ignoreargs;

	do {
		if (interactive)
			printf("%s @ %s %s", getenv("USER"), getenv("PWD"), PS1);
		dsh_read_line(&buf);

		strbrk(buf, &args, ' ', &wc);

		getcmd(args, envp, &pathsplit, &pathc);

		freestuff(args, &wc, buf, pathsplit, &pathc);

	} while (interactive);

	return (0);
}
