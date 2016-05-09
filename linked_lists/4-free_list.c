#include <stdlib.h>
#include "list.h"

void free_list(List *list) {
  List *temp;
  List *temp2;
  temp = list;
  while (temp->next != NULL) {
    temp2 = temp->next;
    free(temp->str);
    free(temp);
    temp = temp2;
  }
  if (temp->next == NULL) {
    free(temp->str);
    free(temp);
  }
}
