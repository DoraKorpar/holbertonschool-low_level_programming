#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

char *string_concat(char *str, char *str2);

char *where_program(char **path_array, char *str)
{
  	int i;
  	char *con_path;
  	struct stat buf;

  	for (i = 0; path_array[i] != NULL; ++i) {
    		con_path = string_concat(path_array[i], str);
    		if (stat(con_path, &buf) == -1) {
    		} else {
      			return con_path;
    		}
  	}
  	return (0);
}
