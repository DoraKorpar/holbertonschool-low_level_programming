#include "str_struct.h"
#include <unistd.h>
int print_char(char c);
void print_number(int n);

void print_string_struct(struct String *str) {
  int i;
  i = 0;

  /* iterates through string, printing each character */
  while (str->str[i] != '\0') {
    print_char(str->str[i]);
    i++;
  }
  print_char(',');
  print_char(' ');
  print_number(str->length);
  print_char('\n');
}

void print_number(int n)
{
  int print_me;
  int power;
  int digit;

  digit = n;
  power = 1;
  while (digit > 9) {
    digit /= 10;
    power *= 10;
  }

  while (n > 0) {
    print_me = n / power;
    n = n % power;
    power /= 10;
    print_char(print_me + '0'); 
 }
}

int print_char(char c)
{
  return (write(1, &c, 1));
}
