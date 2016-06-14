#include <stdarg.h>
#include "printf_header.h"

int c_func(va_list ap)
{
  char c;

  c = va_arg(ap, int);
  print_char(c);
  return (1);
}
