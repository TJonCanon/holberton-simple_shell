#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>

char **dstrtok(char *str, const char delim);

int main(int ac, char **args)
{
	char *PS1 = "$ ";
	size_t nchars = 1024, characters;
	char *buf;
	char **split;
	bool live = true;

	while (!feof(stdin))
	{
		buf = malloc(nchars * sizeof(char));

		printf("%s", PS1);

		characters = getline(&buf, &nchars, stdin);

		split = dstrtok(buf, ' ');

		for (; *split; split++)
		{
			printf("%s\n", *split);
		}
	}

	printf("\nYou killed me!\n");

	return (characters);
}

char **dstrtok(char *str, const char delim)
{
	int i, j = 0;
	short wc = 1, wordlen = 0;
	char **words;

	if (!str)
	{
		perror("Bad String Input");
		return (NULL);
	}

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
			wc++;
	}

	words = malloc(sizeof(char *) * (wc + 1));

	for (i = 0; str[i]; i++, wordlen++)
	{
		if (str[i] == delim || str[i] == 10)
		{
			words[j] = malloc(wordlen * sizeof(char));
			wordlen = 0;
			++i && ++j;
		}
	}

	for (j = 0; j < wc; j++)
	{
		for (i = 0; *str && *str != delim; i++, str++)
		{
			words[j][i] = *str;
		}
		str++;
	}

	return (words);
}
