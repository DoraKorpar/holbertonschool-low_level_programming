#include <stdlib.h>
#include "str_struct.h"

struct String *string_to_struct(char *str) {
  struct String *string;
  int i;
  int j;
  i = 0;
  j = 0;

  while (str[i] != '\0') {
    i++;
  }

  string = malloc(sizeof(struct String));
  if (string == NULL) {
    return (NULL);
  }

  string->str = malloc(sizeof(char) * i);
  if (string->str == NULL) {
    return (NULL);
  }
  
  while (j < i) {
    string->str[j] = str[j];
    j++;
  }

  string->length = i;

  return (string);
}
