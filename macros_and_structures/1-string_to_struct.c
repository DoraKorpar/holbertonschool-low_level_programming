#include <stdlib.h>
#include "str_struct.h"

struct String *string_to_struct(char *str) {
  struct String *sts;
  int i;

  sts = malloc(sizeof(struct String));
  if (sts == NULL) {
    return (NULL);
  }
  
  while (sts->str[i] != '\0') {
    i++;
  }

  sts->str = str;
  sts->length = i;

  return (sts);
}
