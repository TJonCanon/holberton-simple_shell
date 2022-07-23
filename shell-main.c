#include "shell.h"

void freestuff(char **split);
char *lsh_read_line(void);

int main(void)
{
	char *PS1 = "$ ";
	char *buf;
	char **split;
	int i;
	bool live = true;

	while (live)
	{
		printf("%s", PS1);
		/* readline goes here */
		/* buf = calloc(1024, sizeof(char)); */
		/* characters = getline(&buf, &nchars, stdin); */
		buf = lsh_read_line();
		/*and ends here*/
		split = strbrk(buf, ' ');

		for (i = 0; split && split[i]; i++)
		{
			if (split[i][0] == 'x')
				live = false;
			write(1, split[i], strlen(split[i]));
			putchar(10);
		}
	}

	printf("\nYou killed me!\n");

	freestuff(split);

	return (0);
}

void freestuff(char **split)
{
	int i;

	for (i = 0; split[i]; i++)
		putchar(i + '0');

	putchar(10);

	for (i = 0; i < 3; i++)
	{
		free(split[i]);
	}
	free(split);
}
