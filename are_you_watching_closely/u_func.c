#include <stdarg.h>
#include "printf_header.h"

int u_func(va_list ap)
{
  unsigned int u;
  int ret; 

  u = va_arg(ap, unsigned int);
  ret = print_number(u);
  return (ret);
}
