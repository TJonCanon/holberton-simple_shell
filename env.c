#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	int i = 0;

  for (char **env = envp; env[i] != 0; i++)
  {
    char *ourEnv = env[i];
    printf("%s\n", ourEnv);    
  }
  return 0;
}
