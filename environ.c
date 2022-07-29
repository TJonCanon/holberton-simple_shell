#include <unistd.h>
#include <stdio.h>
/**
 * main - 
 * @ac: argc
 * @av: argv
 * @environ: array of pointers to strings called environment
 * Return - void
 */
void main (int ac, char **av, char **environ)
{
	int i = 0;

	(void) ac;
	(void) av;
	while(environ[i]) 
	{
		printf("%s\n", environ[i++]);
	}
}
