#include <stdarg.h>
#include "printf_header.h"

int o_func(va_list ap)
{
  int rem, i, octal, ret;
  unsigned int n;

  i = 1;
  octal = 0;
  n = va_arg(ap, unsigned int);
  while (n != 0) {
    rem = n % 8;
    n /= 8;
    octal += rem*i;
    i *= 10;
  }
  ret = print_number(octal);
  return (ret);
}
