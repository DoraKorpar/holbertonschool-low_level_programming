#include <stdio.h>

int main(void) {
  int n;
  int a[5];
  int *p;

  a[2] = 1024;
  p = &n;
  *(p + 5) = 98;

  printf("&(*(p + 5)) = %p\n", &(*(p + 5)));
  printf("&p = %p\n", &p);
  printf("&a[2] = %p\n", &a[2]);
  printf("a[2] = %d\n", a[2]);
  return (0);
}
