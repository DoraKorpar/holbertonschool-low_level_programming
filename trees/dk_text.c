#include "tree.h"
#include <stdio.h>

BTree *btree_find(BTree *tree, char *str);
int btree_insert(BTree **tree, char *data);

int main(void)
{
  BTree *print_me;
  BTree *tree = NULL;

  printf("The numbers should be in ascending order.\n");
  btree_insert(&tree, "q - 1");
  btree_insert(&tree, "w - 6");
  btree_insert(&tree, "e - 2");
  btree_insert(&tree, "f - 5");
  btree_insert(&tree, "u");
  btree_insert(&tree, "r - 7");
  btree_insert(&tree, "t - 8");
  printf("Inserted all nodes\n");
  print_me = btree_find(tree, "u");
  if (print_me == NULL)
	  {
		  printf("tree was NULL\n");
		  return (1);
	  }
  printf("%s\n", print_me->str);
  return (0);
}
