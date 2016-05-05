#include "str_struct.h"
#include <unistd.h>
int print_char(char c);

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
  /* have to add 48 because print_char assumes ascii value */
  print_char((str->length) + 48);
  print_char('\n');
}

int print_char(char c)
{
  return (write(1, &c, 1));
}
