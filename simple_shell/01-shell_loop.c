#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "libshell.h"

int print_char(char c);
void (*built_in_func(char *str))(char **env);
int program_exec(char **args, char **env);

void shell_loop(char **env)
{
	void (*func_ptr)(char **env);
  	char **args;
  	char *line;
  	char str[23] = "D's_awesome_prompt >> ";
  	int i;

 	/* prints prompt string continually */
  	while (1) {
    		for (i = 0; str[i] != '\0'; ++i) {
      			print_char(str[i]);
    		}
    		
    		/* read_line stores string of everything typed in terminal and string_split parses it */
    		line = read_line(0);
    		args = string_split(line, ' ');

    		/* THIS IF CONDITION DETERMINES WHETHER TYPED COMMAND IS BUILTIN FUNC OR PROGRAM */
    		i = 0;
    		func_ptr = built_in_func(args[i]);
    		if (func_ptr == 0) {
      			program_exec(args, env);
    		} else {
      			(*func_ptr)(env);
    		}

    		/* free everything malloced in functions used */
     		while (args[i] != NULL) {
      			free(args[i]);
      			++i;
    		}
    		free(args);
		free(line);
  	}
}
