#include <stdarg.h>
#include <limits.h>
#include "printf_header.h"

int printf(const char *format, ...)
{
  va_list ap;
  int i, ret, count;

  va_start(ap, format);
  i = 0;
  count = 0;
  while (format[i] != '\0') {
    if (format[i] == '%') {
      /* if format[i+1] is not percent, sends it to be evaluated */
      ret = manage_funcs(format[i + 1], ap);
      if (ret > 0) {
        i++;
	/* ret-2 accounts for percent and specifier */
	count += (ret - 2);
      } else {
	print_char(format[i]);
      }
    } else {
      print_char(format[i]);
    }
    i++;
  }
  count += i;
  va_end(ap);
  return (count);
}
