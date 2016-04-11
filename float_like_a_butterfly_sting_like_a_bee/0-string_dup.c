#include <stdlib.h>

/* function counts length of array, then returns a new array of that length containing the previous one */
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
