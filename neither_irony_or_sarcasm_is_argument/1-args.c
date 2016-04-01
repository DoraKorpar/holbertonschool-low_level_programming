#include <stdio.h>

int main(int ac, char **av) {
  while (ac--) {
    printf("%s\n", *av++);
  }
  return (0);
}
