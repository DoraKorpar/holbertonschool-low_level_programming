#include "str_struct.h"
#include <stdlib.h>

struct String *string_to_struct(char *str);
void print_string_struct(struct String *str);

int main(void)
{
  struct String *str;

  str = string_to_struct("Holberton");
  if (str == NULL) {
    return (1);
  }
  print_string_struct(str);
  return (0);
}
