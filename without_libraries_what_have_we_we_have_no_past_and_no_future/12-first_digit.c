#include <limits.h>

int first_digit_pos(int n);

int first_digit(int n)
{
  if (n > 0) {
    return (first_digit_pos(n));
  }
  else if (n == 0) {
    return (0);
  }
  else if (n == INT_MIN) {
    n = n + 1;
    n = -n;
    return (first_digit_pos(n));
  }
  else {
    n = -n;
    return (first_digit_pos(n));
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
