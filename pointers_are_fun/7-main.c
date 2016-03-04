#include <stdio.h>

void modif_my_param(int *m)
{
  printf("Value of 'm': %p\n", m);
  printf("Address of 'm': %p\n", &m);
  *m = 402;
}

int main(void)
{
  int n;
  int *p;

  p = &n;
  n = 98;
  printf("Value of 'n' before the call: %d\n", n);
  printf("Address of 'n': %p\n", &n);
  printf("Value of 'p': %p\n", p);
  printf("Address of 'p': %p\n", &p);
  modif_my_param(p);
  printf("Value of 'n' after the call: %d\n", n);
  return (0);
}
