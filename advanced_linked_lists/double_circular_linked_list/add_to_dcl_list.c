#include <string.h>
#include <stdlib.h>
#include "list.h"

int add_end_dcl_list(List **list, char *str) 
{
  List *node;
  List *temp;
  List *first;

  node = malloc(sizeof(List));
  if (node == NULL) {
    return (1);
  }

  node->str = strdup(str);
  if (*list == NULL) {
    *list = node;
  }
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
  }
  node->next = *list;
  first = *list;
  first->prev = node;
  return (0);
}

int add_begin_dcl_list(List **list, char *str)
{
  List *node;
  List *temp;
  List *first;

  node = malloc(sizeof(List));
  if (node == NULL) {
    return (1);
  }

  node->str = strdup(str);
  if (*list == NULL) {
    node->next = node;
  }
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
    node->next = *list;
    first = *list;
    first->prev = node;
  }
  *list = node;
  return (0);
}
