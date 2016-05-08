#include <stdlib.h>
#include <unistd.h>
#include "list.h"
int print_char(char c);

void print_list(List *list) {
  List *temp;
  int i;
  temp = list;
  i = 0;
  /* for every node but the last one, print the contents of str, followed by a comma and space */
  while (temp->next != NULL) {
    while (temp->str[i] != '\0') {
      print_char(temp->str[i]);
      i++;
    }
    print_char(',');
    print_char(' ');
    temp = temp->next;
  }
  /* i reinitialized to 0 for next loop */
  i = 0;
  /* for last node of the list */
  if (temp->next == NULL) {
    while (temp->str[i] != '\0') {
      print_char(temp->str[i]);
      i++;
    }
  }
  print_char('\n');
}

int print_char(char c)
{
  return (write(1, &c, 1));
}
