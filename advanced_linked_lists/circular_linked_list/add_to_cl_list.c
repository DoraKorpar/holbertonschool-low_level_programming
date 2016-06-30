#include <string.h>
#include <stdlib.h>
#include "list.h"

int add_end_cl_list(List **list, char *str) 
{
  List *node;
  List *temp;

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
  }
  node->next = *list;
  return (0);
}

int add_begin_cl_list(List **list, char *str)
{
  List *node;
  List *temp;

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
    node->next = *list;
  }
  *list = node;
  return (0);
}
