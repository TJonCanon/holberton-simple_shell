#include <unistd.h>
#include <stdio.h>

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
