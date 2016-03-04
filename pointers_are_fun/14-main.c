#include <stdio.h>

int main(void)
{
  int array[10];
  int *p;

  p = array;
  printf("sizeof array: %lu\n", sizeof(array));
  printf("sizeof p: %lu\n", sizeof(p));
  return (0);
}
