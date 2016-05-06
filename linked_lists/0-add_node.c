#include <stdlib.h>
#include "list.h"
char *string_dup(char *);

int add_node(List **list, char *str) {
  List *l;
  
  /* allocate memory to node */
  l = malloc(sizeof(List));
  if (l == NULL) {
    return (1);
  }

  /* populate node with copy of string passed as param */
  l->str = string_dup(str);
  /* next takes address in list because it is added to the beginning of the linked list */
  l->next = *list;
  /* list pointer then given value of l because it is the first node */
  *list = l;  
  
  return (0);
}

/* function counts length of array, then returns a new array of that length containing the previous one */
char *string_dup(char *str) {
  char *str_copy = str;
  int i = 0;
  int j;
  while (str[i] != '\0') {
    i++;
  }
  str = malloc(sizeof(char) * i);
  if (str == NULL) {
    return (0);
  }
  for (j = 0; j < i; j++) {
    str[j] = str_copy[j];
  }
  return (str);
}
