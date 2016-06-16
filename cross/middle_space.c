#include "cross_head.h"

void middle_space(int i)
{
  int j;

  for (j = (i - 1)/2; j > 0; j--) {
    print_char(' ');
  }
}
