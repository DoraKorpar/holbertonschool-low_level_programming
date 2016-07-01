#include "list.h"

void print_string(char *);
int print_char(char);
void print_last_node(List *);

void print_cl_list(List *list)
{
  List *node;

  node = list;
  /* prints all but last node */
  while (node->next != list) {
    print_string(node->str);
    print_char('\n');
    print_char('\t');
    print_string(node->next->str);
    print_char('\n');
    node = node->next;
  }
  /* prints last node */
  print_last_node(node);
}

void print_last_node(List *node)
{
  print_string(node->str);
  print_char('\n');
  print_char('\t');
  print_string(node->next->str);
  print_char('\n');
}
