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
  /* if linked list is empty, list pointer will point to new node */
  if (*list == NULL) {
    *list = node;
  }
  /* if ll is not empty, last node of list will point to new node */
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    temp->next = node;
    node->prev = temp;
  }
  /* makes ll circular */
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
  /* if list is empty, new node points to itself */
  if (*list == NULL) {
    node->next = node;
  }
  else {
    temp = *list;
    while (temp->next != *list) {
      temp = temp->next;
    }
    /* if list is not empty, last node links to new node and vice versa to make double circular */
    temp->next = node;
    node->prev = temp;
    node->next = *list;
    first = *list;
    first->prev = node;
  }
  *list = node;
  return (0);
}
