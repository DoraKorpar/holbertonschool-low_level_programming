#include <stdio.h>

int advanced_search(int *p, int i, int (*check_func)(int)) {
  int j;
  for (j = 0; j < i; j++) {
    int comp = (*check_func)(p[j]);
    if (comp == 1) {
      return (j);
    }
  }
  return(-1);
}
