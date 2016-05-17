#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "libshell.h"

void shell_loop(char **env);

int main(__attribute__((unused)) int ac, __attribute__((unused)) char **av, char **env)
{
  	shell_loop(env);
  	return (0);
}
