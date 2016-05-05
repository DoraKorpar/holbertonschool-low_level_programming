#include "str_struct.h"
#include <stdlib.h>

void free_string_struct(struct String *str) {
  /* first free string within struct, then struct itself */
  free(str->str);
  free(str);
} 
