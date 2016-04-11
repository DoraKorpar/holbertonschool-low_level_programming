#include <stdlib.h>
#include <stdio.h>

/* function takes two arrays and prints them into one */
char *string_nconcat(char *s1, char *s2, int n) {
  int i = 0, j = 0, l = 0, k;
  char *mem;
  while (s1[i] != '\0') {
    i++;
  }
  while (s2[j] != '\0') {
    j++;
  }

  k = i + j;
  mem = malloc(sizeof(char) * k);
  if (mem == NULL) {
    return (0);
  }

  while (l < (i)) {
    mem[l] = s1[l];
    l++;
  }
  l = 0;
  while (l < n) {
    mem[i+l] = s2[l];
    l++;
  }
  return (mem);
}
