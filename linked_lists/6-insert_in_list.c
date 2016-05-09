#include <stdlib.h>
#include "list.h"
int list_size(List *list);
int add_node_2(List **list, char *content);
char *string_dup(char *str);

int insert_in_list(List **list, char *content, int index) {
  List *newNode;

  newNode = malloc(sizeof(newNode));
  newNode = *list;

  if (index < 0) {
    return (0);
  }
  if (index > list_size(*list)) {
    add_node_2(list, content);
  }
  while (index > 1) {
    newNode = newNode->next;
    index--;
  }
  newNode->str = string_dup(content);
  return (0);
}

int list_size(List *list) {
  int i;
  List *temp;
  i = 1;
  temp = list;
  while (temp->next != NULL) {
    i++;
    temp = temp->next;
  }
  return (i);
}

int add_node_2(List **list, char *content) {
  List *newNode;
  List *temp;
  newNode = malloc(sizeof(List));
  if (newNode == NULL) {
    return (1);
  }
  newNode->str = string_dup(content);
  newNode->next = NULL;
  if (*list == NULL) {
    *list = newNode;
  }
  else {
    temp = *list;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
  return (0);  
}
