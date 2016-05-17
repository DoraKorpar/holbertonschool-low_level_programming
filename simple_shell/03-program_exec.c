#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "libshell.h"

char *where_program(char **array, char *str);
char *find_path(char **env);

int program_exec(char **args, char **env)
{
  	pid_t pid;
  	int status;
  	char **exec_args;
  	char *path_only;
  	char **path_array;
  	int i;

  	/* finds how long args array is */
  	for (i = 0; args[i] != NULL; ++i);
  	exec_args = malloc(sizeof(char *) * i);
  	if (exec_args == NULL) {
      		perror("Error with malloc\n");
      		return (0);
  	}

  	path_only = find_path(env);
  	path_array = string_split(path_only, ':');
  	exec_args[0] = where_program(path_array, args[0]);
  	/* printf("exec_args[0]: %s\n", exec_args[0]); */

  	/* checks if command has argument and stores it to array */
  	if (args[1] != NULL) {
    		exec_args[1] = args[1];
    		exec_args[2] = NULL;
  	} else {
    		exec_args[1] = NULL;
    	}

  	if ((pid = fork()) == -1) {
    		perror("fork");
    		return (1);
  	}
  	if (pid == 0) {
    		execve(exec_args[0], exec_args, env);
		i = 0;
	  	while (exec_args[i]) {
	      		free(exec_args[i]);
	      		++i;
	  	}
	  	free(exec_args);
	  	free(path_only);
	  	i = 0;
	  	while (path_array[i]) {
	    		free(path_array[i]);
	    		++i;
	  	}

  	} else {
    		wait(&status);
		i = 0;
	  	while (exec_args[i]) {
	      		free(exec_args[i]);
	      		++i;
	  	}
	  	free(exec_args);
	  	free(path_only);
	  	i = 0;
	  	while (path_array[i]) {
	    		free(path_array[i]);
	    		++i;
  		}
	}
  	return (0);
}
