#include <stdio.h>

int main(void)
{
  int array[10];
  int array2[10];
  int *p;
  int n;

  p = &n;
  p = array;
  array = &n;
  array = p;
  array = array2;
  return (0);
}
