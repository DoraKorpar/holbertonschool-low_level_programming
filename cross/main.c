#include "cross_head.h"

int main(int ac, char **av)
{
  int n;

  if (ac < 2) {
    return (1);
  }
  
  n = string_to_integer(av[1]);
  if (n <= 0) {
    return (1);
  }
  else {
    print_cross(n);
  }
  return (0);
}
