#include "my_functions.h"
#include <limits.h>

void print_number_pos(int n);

/* this is the main function */
void print_number(int n)
{
  if (n > 0)
    {
      print_number_pos(n);
    }
  if (n == 0)
    {
      print_char('0');
    }
  if (n < 0)
    {
      n = -n;
      print_char('-');
      print_number_pos(n);
    }
}

void print_number_pos(int n)
{
  int n2 = n;
  int power = 1;
  int print;
  while (n2 > 9)
    {
      n2 /= 10;
      power *= 10;
    }

  while (n > 0)
    {
      print = n / power;
      n = n % power;
      power /= 10;
      print_char(print + 48);
    }
}
