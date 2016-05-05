#include <stdio.h>
#include "str_struct.h"

void print_string_struct(struct String *str) {
  printf("%s, %d\n", str->str, str->length);
}
