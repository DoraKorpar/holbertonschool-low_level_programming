#include "printf_header.h"

int perc_func(__attribute__((unused)) va_list ap)
{
  /* prints percentage when double percentages are in printf */
  print_char('%');
  return (1);
}
