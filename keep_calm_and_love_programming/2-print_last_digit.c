#include "my_functions.h"

void print_positive(int n);

void print_last_digit(int n)
{
  if (n > 0) {
    print_positive(n);
  }
  if (n == 0) {
    print_char('0');
  }
  if (n < 0) {
    n = -n;
    print_positive(n);
  }
}

void print_positive(int n)
{
  int print_me;
  int power;
  int digit;

  digit = n;
  power = 1;
  while (digit > 9) {
    digit /= 10;
    power *= 10;
  }

  while (n > 0) {
    print_me = n / power;
    n = n % power;
    power /= 10;
    /*print_char(print_me + '0'); */
  }
  print_char(print_me + '0');
}
