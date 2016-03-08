#include "my_functions.h"

/* prints every character until the null, which signifies the end of a string */
void print_string(char *str)
{
  int x = 0;
  while (*(str + x) != 0) {
    print_char(*(str +x));
    x++;
  }
}
