#include <stdio.h>

/* loops and adds one to len for every loop, finding length of string */
int str_len(char *str)
{
  int len = 0;
  while (*(str + len) != 0) {
    len++;
  }
  return (len);
}
