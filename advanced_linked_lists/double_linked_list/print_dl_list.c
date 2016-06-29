#include <stdio.h>
#include "list.h"

void print_string(char *);
int print_char(char);

void print_dl_list(List *list)
{
  List *node;

  node = list;

  while (node->next) {
    print_string(node->str);
    print_char('\n');
    
    if (node->prev == NULL) {
      print_string("\tNULL\n");
    }
    else {
      print_char('\t');
      print_string(node->prev->str);
      print_char('\n');
    }

    if (node->next == NULL) {
      print_string("\tNULL\n");
    }
    else {
      print_char('\t');
      print_string(node->next->str);
      print_char('\n');
    }
    node = node->next;
  }
}
