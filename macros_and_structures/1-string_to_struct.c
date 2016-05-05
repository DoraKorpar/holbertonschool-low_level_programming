#include <stdlib.h>
#include "str_struct.h"

struct String *string_to_struct(char *str) {
  struct String *string;
  int i;
  int j;
  i = 0;
  j = 0;

  /* finds length of string param */
  while (str[i] != '\0') {
    i++;
  }

  /* allocates memory to struct */
  string = malloc(sizeof(struct String));
  if (string == NULL) {
    return (NULL);
  }

  /* allocates memory to string within struct */
  string->str = malloc(sizeof(char) * i);
  if (string->str == NULL) {
    return (NULL);
  }
  
  /* copies string param into struct string */
  while (j < i) {
    string->str[j] = str[j];
    j++;
  }

  string->length = i;

  return (string);
}
