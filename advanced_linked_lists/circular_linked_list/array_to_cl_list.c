#include <stdio.h>
#include "list.h"

int add_end_cl_list(List **, char *);

List *array_to_cl_list(char **array)
{
  List *list;
  int i;

  list = NULL;
  i = 0;
  while(array[i]) {
    /* adds each element of array to end of list */
    if (add_end_cl_list(&list, array[i]) == 1) {
      return (NULL);
    }
    i++;
  }
  return (list);
}
