#include <stdarg.h>
#include "printf_header.h"

int di_func(va_list ap)
{
  int d, ret;

  d = va_arg(ap, int);
  ret = print_number(d);
  return (ret);
}
