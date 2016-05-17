#include <stdio.h>
#include <stdlib.h>

char *string_concat(char *path_string, char *str)
{
  	int i;
  	int j;
  	char *path_copy = path_string;

  	i = 0;
  	j = 0;
  	/* stores length of each string for mallocing */
  	while (path_string[i] != '\0') {
    		++i;
  	}
  	while (str[j] != '\0') {
    		++j;
  	}

  	/* allocates enough memory for path_string to hold str and an extra slash and null terminator */
  	path_string = malloc(sizeof(char) * (i + j + 2));
    	if (path_string == NULL) {
        	perror("Malloc error");
        	return (0);
    	}

  	for (i = 0; path_copy[i] != '\0'; ++i) {
      		path_string[i] = path_copy[i];
  	}
  	/* adds another slash to the string before the command */
  	path_string[i] = '/';
  	++i;
  	for (j = 0; str[j] != '\0'; ++i, ++j) {
    		path_string[i] = str[j];
  	}
  	path_string[i + 1] = '\0';
  	return path_string;
}
