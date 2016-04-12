#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
char *int_to_string(int n) {
  int num_digits = 1, power = 1, print_me, ncopy = n, i = 0;
  char *string_array;

  if (n < 0 && n > INT_MIN) {
    ncopy = -n;
  }
  if (n == INT_MIN) {
    ncopy = 214748364;
  }
  while (ncopy > 9) {
    ncopy /= 10;
    power *= 10;
    num_digits++;
  }

  string_array = malloc(sizeof(char) * (num_digits + 2));
  if (string_array == NULL) {
    return (0);
  }

  if (n == 0) {
    string_array[0] = '0';
    string_array[1] = 0;
  }

  if (n < 0 && n > INT_MIN) {
    string_array[0] = '-';
    i = 1;
    n = -n;
  }
  if (n == INT_MIN) {
    string_array[0] = '-';
    i = 1;
    n = 214748364;
    string_array[10] = '8';
  }

  while (n > 0) {
    print_me = n / power;
    n %= power;
    power /= 10;
    string_array[i] = (print_me + '0');
    i++;
  }
  string_array[num_digits + 3] = 0;
  return (string_array);
}
