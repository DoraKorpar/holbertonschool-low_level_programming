#include <stdlib.h>
#include <string.h>
#include "list.h"

int add_end_dl_list(List **list, char *str)
{
  List *node;
  List *temp;
  
  /* allocate space in memory for new node */
  node = malloc(sizeof(List));
  if (node == NULL)
    return (1);

  /* fill in content of node */
  node->str = strdup(str);
  node->next = NULL;

  /* sets pointer to list to node only if list is empty */
  if (*list == NULL) {
    *list = node;
    node->prev = NULL;
  }

  /* finds last node in list and stores address in temp to use for node linking */
  else { 
    temp = *list;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
  }
  return (0);
}

int add_begin_dl_list(List **list, char *str)
{
  List *node;
  List *temp;
  
  /* allocate space in memory for new node */
  node = malloc(sizeof(List));
  if (node == NULL)
    return (1);

  /* fill in content of node */
  node->str = strdup(str);
  node->next = *list;
  node->prev = NULL;

  /* sets previous first node->prev and pointer to list to point to new node if list isn't empty */
  if (*list != NULL) {
    temp = *list;
    temp->prev = node;
  }
  *list = node;

  return (0);
}
