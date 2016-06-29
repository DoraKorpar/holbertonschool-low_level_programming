#include <stdlib.h>
#include <stdio.h>
#include "list.h"

List *array_to_dl_list(char **);

int main(__attribute__((unused))int ac, char **av)
{
  List *list;

  list = array_to_dl_list(av);
  if (list == NULL)
    return (1);

  printf("The nodes in the list contain the strings:\n");
  printf("%s\n", list->next->next->next->next->prev->prev->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->str);
  printf("%s\n", list->next->next->next->next->str);

  return (0);
}
