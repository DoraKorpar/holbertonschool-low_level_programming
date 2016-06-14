#include <stdarg.h>
#include "printf_header.h"

int p_func(va_list ap)
{
  unsigned long int addr, rem;
  int i, j, ret;
  char hex_addr[100];

  i = 1;
  addr = va_arg(ap, unsigned long int);
  /* converts decimal to hex char and stores it in array */
  while (addr != 0) {
    rem = addr % 16;
    if (rem < 10) {
      rem += 48;
    } else {
      rem += 87;
    }
    hex_addr[i++] = rem;
    addr /= 16;
  }
  /* ret needs to be length of array plus two for printed chars */
  print_char('0');
  print_char('x');
  j = i - 1;
  ret = j + 2;

  while (j > 0) {
    print_char(hex_addr[j]);
    j--;
  }
  return (ret);
}
