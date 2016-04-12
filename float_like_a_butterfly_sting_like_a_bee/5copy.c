#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
char *int_to_string(int n) {
  int num_digits = 1, power = 1, print_me, ncopy = n, i = 0;
  char *string_array;
  while (ncopy > 9) {
    ncopy /= 10;
    power *= 10;
    num_digits++;
  }

  string_array = malloc(sizeof(char) * num_digits);
  if (string_array == NULL) {
    return (0);
  }

  while (n > 0) {
    print_me = n / power;
    n %= power;
    power /= 10;
    string_array[i] = (print_me + '0');
    i++;
  }
  return (string_array);
}


