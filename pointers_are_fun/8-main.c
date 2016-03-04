#include <stdio.h>

void modif_my_char(char *cc, char ccc)
{
  *cc = 'o';
  ccc = 'l';
  printf("Value of cc: %p\n", cc);
}

int main(void)
{
  char c;
  char *p;

  p = &c;
  c = 'H';
  printf("Value of c: %c\n", c);
  printf("Value of p: %p\n", p);
  modif_my_char(p, c);
  printf("Value of c after modif: %c\n", c);
  printf("Value of p after modif: %p\n", p);
  return (0);
}
