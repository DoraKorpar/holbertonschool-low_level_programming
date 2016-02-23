#include <limits.h>

int first_digit(int n)
{
  if (n > 0) {
    first_digit_pos(n);
  }
  if (n == 0) {
    return (0);
  }
  if (n == INT_MIN) {
    n = n + 1;
    n = -n;
    first_digit_pos(n);
    }
  if (n < 0) {
    n = -n;
    first_digit_pos(n);
  }
}

int first_digit_pos(int n)
{
  while (n > 9)
    {
      n = n / 10;
    }
  return (n);
}
