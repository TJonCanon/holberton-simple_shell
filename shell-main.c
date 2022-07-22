#include "shell.h"

int main(int ac, char **args)
{
	char *PS1 = "$ ";
	size_t nchars = 0, characters;
	char *buf = NULL;
	char **split;
	bool live = true;

	while (!feof(stdin))
	{
		printf("%s", PS1);

		characters = getline(&buf, &nchars, stdin);

		split = strbrk(buf, ' ');

		for (; *split; split++)
		{
			printf("%s\n", *split);
		}
	}

	printf("\nYou killed me!\n");

	return (characters);
}
