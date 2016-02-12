#include "my_functions.h"

void print_combination_1(void)
{
  int n;
  for (n = 0; n < 9; n++)
    {
      print_char((n + 48));
      print_char(',');
      print_char(' ');
    }
  if (n == 9)
    {
      print_char('9');
    }
}

