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

  /* populates data in node */
  node->str = strdup(str);
  /* if linked list is empty, make pointer to list point to new node */
  if (*list == NULL) {
    *list = node;
  }
  /* if linked list is not empty, assigns previously last node->next to new node */
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    temp->next = node;
  }
  /* next of new node links to whatever pointer to list points to */
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
  /* if list is empty, new node points to itself */
  if (*list == NULL) {
    node->next = node;
  }
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    /* last node in list points to new node to make it circular */
    temp->next = node;
    node->next = *list;
  }
  *list = node;
  return (0);
}
