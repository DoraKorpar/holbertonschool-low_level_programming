#include <stdlib.h>
#include "list.h"

void free_cl_list(List *list)
{
  List *temp;
  List *other;

  temp = list;
  /* loops frees every node but last b/c stops where node->next equals first node */
  while (temp->next != list) {
    other = temp;
    temp = temp->next;
    free(other->str);
    free(other);
  }
  /* frees last node */
  free(temp->str);
  free(temp);
}
