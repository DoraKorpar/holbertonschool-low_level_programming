#include <stdio.h>
#include <unistd.h>

int string_compare(char *s1, char *s2);
int print_env(char **env);
int exit_shell(char **arr);

int (*built_in_func(char *str))(char **env)
{
	/* command is an array of known built-in commands */
	char *command[3] = {"env", "exit", NULL};
  	int (*func_addrs[2])(char **) = {&print_env, &exit_shell};
  	int i;
  	int comp;

  	i = 0;
	/* string_compare returns 0 if the two strings match */
	while (command[i] != NULL) {
    		comp = string_compare(str, command[i]);
    		if (comp == 0) {
      			return (func_addrs[i]);
    		}
    		++i;
  	}
  	return (0);
}
