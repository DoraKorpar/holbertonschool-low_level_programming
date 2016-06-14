#include "printf_header.h"

typedef struct speficier_funcs {
  char spec;
  int (*spec_func)(va_list ap);
} spec_func;

int manage_funcs(char c, va_list ap)
{
  spec_func f[] = { {'d', &di_func}, {'i', &di_func}, {'o', &o_func}, {'u', &u_func}, {'x', &x_func}, {'X', &X_func}, {'c', &c_func}, {'s', &s_func}, {'p', &p_func}, {'%', &perc_func}, {'\0', '\0'} };
  int i, ret;

  i = 0;
  while (f[i].spec != '\0') {
    if (c == f[i].spec) {
      ret = f[i].spec_func(ap);
      return (ret);
    }
    i++;
  }
  return (0);
}
