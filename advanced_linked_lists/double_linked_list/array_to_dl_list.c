#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dl_list(List **, char *);

List *array_to_dl_list(char **array)
{
  List *list;
  int i;

  list = NULL;
  i = 0;
  while (array[i]) {
    /* function adds each arg to end of list, and handles errors */
    if (add_end_dl_list(&list, array[i]) == 1) {
      return NULL;
    }
    i++;
  }
  
  return (list);
}
