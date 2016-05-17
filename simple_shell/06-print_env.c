#include <stdio.h>

int print_char(char c);

int print_env(char **env)
{
  	int i;
  	int j;
  	for (i = 0; env[i]; ++i) {
    		for (j = 0; env[i][j]; ++j) {
      			print_char(env[i][j]);
    		}
  		print_char('\n');
  	}
  	return (0);
}
