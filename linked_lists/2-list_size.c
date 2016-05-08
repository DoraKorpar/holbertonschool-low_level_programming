#include <stdlib.h>
#include "list.h"

int list_size(List *list) {
  int i;
  List *temp;
  /* i is initialized at one because list starts at first node */
  i = 1;
  temp = list;
  while (temp->next != NULL) {
    i++;
    temp = temp->next;
  }
  return (i);
}
