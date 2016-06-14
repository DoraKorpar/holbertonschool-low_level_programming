#include "printf_header.h"

int print_positive(long int n);

int print_number(long int n) {
  if (n == 0) {
    print_char('0');
    return (1);
  }
  if (n > 0) {
    print_positive(n);
  }
  if (n < 0) {
    print_char('-');
    n = -n;
    print_positive(n);
  }
}

int print_positive(long int n) {
  long int ncopy;
  int power, i;
  int print_me;
  ncopy = n;
  power = 1;
  i = 1;
  while (ncopy > 9) {
    ncopy /= 10;
    power *= 10;
    i++;
  }
  while (n > 0) {
    print_me = n / power;
    n = n % power;
    power /= 10;
    print_char(print_me + 48);
  }
  return (i);
}
