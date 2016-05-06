#include <stdlib.h>
#include "list.h"
char *string_dup(char *str);

int add_node(List **list, char *content) {
  
}

char *string_dup(char *str) {
  char *str_copy = str;
  int i = 0;
  int j;
  while (str[i] != '\0') {
    i++;
  }
  str = malloc(sizeof(char) * i);
  if (str == NULL) {
    return (0);
  }
  for (j = 0; j < i; j++) {
    str[j] = str_copy[j];
  }
  return (str);
}
