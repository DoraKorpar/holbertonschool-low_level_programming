#include <stdlib.h>

char *string_dup(char *str) {
  int i;
  int j;
  char *str_copy = str;
  i = 0;
  j = 0;
  while (str[i] != 0) {
    i++;
  }
  str = (char *)malloc(i);
  if (str == NULL) {
    return (0);
  }

  while (j < i) {
    str[j] = str_copy[j];
    j++;
  }
  return (str);
}
