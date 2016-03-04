#include "my_functions.h"

void print_string(char *str)
{
  int x = 0;
  while (*(str + x) != 0) {
    print_char(*(str +x));
    x++;
  }
}
