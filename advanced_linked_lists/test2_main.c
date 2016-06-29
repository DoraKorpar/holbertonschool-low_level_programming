#include <stdlib.h>
#include <stdio.h>
#include "list.h"
int add_begin_dl_list(List **, char *);

int main(void)
{
  List *list;

  list = NULL;
  printf("The address stored in list is %p.\n", (void *)list);
  if (add_begin_dl_list(&list, "Holberton") == 1 ||
      add_begin_dl_list(&list, "School") == 1 ||
      add_begin_dl_list(&list, "Full") == 1 ||
      add_begin_dl_list(&list, "Stack") == 1 ||
      add_begin_dl_list(&list, "Engineer") == 1)
    return (1);

  printf("The address stored in list is now %p.\n", (void *)list);

  printf("The nodes in the list contain the strings:\n");
  printf("%s\n", list->next->next->next->next->prev->prev->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->prev->str);
  printf("%s\n", list->next->next->next->next->prev->str);
  printf("%s\n", list->next->next->next->next->str);

  return (0);
}
