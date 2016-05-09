#include <stdlib.h>
#include "list.h"

void remove_from_list(List **list, int index) {
  List *remove_me;
  List *prev_node;
  int i;
  remove_me = *list;
  prev_node = *list;
  i = index - 1;

  /* sets address of node before the one to be removed to prev_node */
  while (i > 0) {
    prev_node = prev_node->next;
    i--;
  }

  while (index > 0) {
    remove_me = remove_me->next;
    index--;
  }
  free(remove_me->str);
  free(remove_me);
  /* removes node from list */
  prev_node->next = remove_me->next;
}
