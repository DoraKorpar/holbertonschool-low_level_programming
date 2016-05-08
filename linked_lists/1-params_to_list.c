#include <stdlib.h>
#include "list.h"
char *string_dup(char *);
int add_node(List **list, char *content);

List *params_to_list(int ac, char **av) {
  List *list; 
  int i;
  list = NULL;
  i = 0;
    while (i < ac) {
      add_node(&list, av[i]);
      i++;
    }
  return (list);
}

char *string_dup(char *str) {
  char *str_copy = str;
  int i = 0;
  int j;
  while (str[i] != '\0') {
    i++;
  }
  str = malloc(sizeof(char) * (i + 1));
  if (str == NULL) {
    return (0);
  }
  for (j = 0; j < i; j++) {
    str[j] = str_copy[j];
  }
  return (str);
}

int add_node(List **list, char *content) {
  List *newNode;
  List *temp;
  /* allocate mem to node */
  newNode = malloc(sizeof(List));
  if (newNode == NULL) {
    return (1);
  }
  /* populate node with copy of param string */
  newNode->str = string_dup(content);
  /* next points to NULL because the new node will be last in the list */
  newNode->next = NULL;
  /* if statement assigns newNode location to *list if it is the first node added to the list */
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
 
