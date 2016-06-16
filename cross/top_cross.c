#include "cross_head.h"

void top_cross(int i)
{
  int j, icopy1, icopy2, jcopy;

  /* icopy1 needs to be i -1 so when divided by two, correct number of rows is printed */
  icopy1 = i - 1;
  for (j = 0; j < (icopy1 / 2); j++) {
    /* prints spaces before first slash, which is same as j */
    for (jcopy = j; jcopy > 0; jcopy--) {
      print_char(' ');
    }
    print_char('\\');
    /* prints spaces between slashes, which is always two less than i */
    for (icopy2 = (i - 2); icopy2 > 0; icopy2--) {
      print_char(' ');
    }
    print_char('/');
    /* prints spaces after slashes, which is same as amount before slashes */
    for (jcopy = j; jcopy > 0; jcopy--) {
      print_char(' ');
    }
    print_char('\n');
    /* increments i for number of spaces between slashes */
    i -= 2;
  }
}
