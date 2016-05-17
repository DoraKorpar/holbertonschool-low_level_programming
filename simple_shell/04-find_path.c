#include <stdlib.h>
#include <stdio.h>

char *find_path(char **env)
{
	int j, k, l;
	char *path_only;

	for (j = 0; env[j] != NULL; ++j) {
  		/* checks if first four characters of env element spell out PATH */
  		if (env[j][0] == 80 && env[j][1] == 65 && env[j][2] == 84 && env[j][3] == 72) {
    			/* stores length of string in k */
    			for (k = 4; env[j][k] != '\0'; ++k);

    			path_only = malloc(sizeof(char) * (k + 1));
      			if (path_only == NULL) {
          			perror("Error with second malloc");
          			return (0);
      			}
    			/* reinitialize k at 4 to begin transferring the string of paths from env to path_only */
    			k = 4;
    			l = 0;
    			while (env[j][k] != '\0') {
       				path_only[l] = env[j][k];
       				++k;
       				++l;
    			}
    			/* path_only[l + 1] = '\0'; */
    			return path_only;
  		}
	}
	return (0);
}
