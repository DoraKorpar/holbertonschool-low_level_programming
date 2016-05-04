#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int ac, char **av) {
  int i;
  for(i = 0; i < ac; i++)
    {
      int j = 0;
      if(av[i][j] == '-' && av[i][j + 1] != '-') {
        j = j + 1;
        while(av[i][j] != '\0') {
	         printf("%c\n", av[i][j]);
	          j++;
        }
      }
      if(av[i][j] == '-' && av[i][j + 1 ] == '-' && av[i][j + 2] != 0) {
        j = j + 2;
       printf("%s\n", av[i]);
      }
    }
    return (0);
}
