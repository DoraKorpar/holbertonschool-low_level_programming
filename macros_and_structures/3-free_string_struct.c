#include "str_struct.h"
#include <stdlib.h>

void free_string_struct(struct String *str) {
  free(str->str);
  free(str);
} 
