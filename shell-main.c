#include "shell.h"

void freestuff(char **split);

extern short wc;
int main(void)
{
	char *PS1 = "$ ";
	size_t nchars = 1024, characters;
	char *buf;
	char **split;
	int i;
	bool live = true;

	while (live)
	{
		buf = calloc(1024, sizeof(char));

		printf("%s", PS1);

		characters = getline(&buf, &nchars, stdin);

		split = strbrk(buf, ' ');

		for (i = 0; split[i]; i++)
		{
			if (split[i][0] == 'x')
				live = false;
			write(1, split[i], strlen(split[i]));
		}
	}

	printf("\nYou killed me!\n");

	freestuff(split);

	return (characters);
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
