#include "printf_header.h"
#include <stdarg.h>

int s_func(va_list ap)
{
  char *str;
  int k;

  str = va_arg(ap, char *);
  /* goes through string and prints each char */
  for (k = 0; str[k] != '\0'; k++) {
    print_char(str[k]);
  }
  return (k);
}
