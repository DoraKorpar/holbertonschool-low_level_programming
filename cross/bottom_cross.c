#include "cross_head.h"

void bottom_cross(int i)
{
  int j, k, kcopy, icopy1, icopy2;

  /* icopy1 will be number of rows to print */
  icopy1 = (i - 1) / 2;
  /* k will be used for the number of spaces between slashes */
  if (i % 2 == 0) {
    k = 2;
  }
  else {
    k = 1;
  }

  for (j = 1; j <= icopy1; j++) {
    /* prints number of spaces before first slash, which decreases by 1 (j) with every new row */
    for (icopy2 = icopy1 - j; icopy2 > 0; icopy2--) {
      print_char(' ');
    }
    print_char('/');
    for (kcopy = k; kcopy > 0; kcopy--) {
      print_char(' ');
    }
    /* number of spaces between slashes increases by 2 with every new row */
    k += 2;
    print_char('\\');
    /* prints same number of spaces as before first slash */ 
    for (icopy2 = icopy1 - j; icopy2 > 0; icopy2--) {
      print_char(' ');
    }
    print_char('\n');
  }
}
