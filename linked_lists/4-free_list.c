#include <stdlib.h>
#include "list.h"

void free_list(List *list) {
  List *temp;
  temp = list;
  while (temp->next != NULL) {
    free(temp->str);
    free(temp);
    temp = temp->next;
  }
  if (temp->next == NULL) {
    free(temp->str);
    free(temp);
  }
}
