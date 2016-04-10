#include <stdlib.h>
#include <stdio.h>

char *string_concat(char *s1, char *s2) {
  int i = 0, j = 0, l = 0;
  int k = i + j;
  char *mem;
  while (s1[i] != '\0') {
    i++;
  }
  while (s2[j] != '\0') {
    j++;
  }
  mem = malloc(sizeof(*s1) * k);








  while (l < (i-1)) {
    mem[l] = s1[l];
    l++;
  }
  while (l < k) {
    mem[l] = s2[l];
    l++;
  }
  return (mem);
}
