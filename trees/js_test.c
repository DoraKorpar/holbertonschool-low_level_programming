#include "tree.h"
#include <stdio.h>

int btree_depth(BTree *);
void btree_free(BTree *tree);
int btree_insert(BTree **tree, char *data);
void print_preorder(BTree *tree);
int test_insert();

int main() {
  test_insert();
  return (0);
}

int test_insert() {
  BTree *tree;
  int depth;
  printf("The numbers should be in ascending order.\n");

  tree = NULL;
  btree_insert(&tree, "q - 1");
  btree_insert(&tree, "w - 6");
  btree_insert(&tree, "e");
  btree_insert(&tree, "r - 7");
  /* btree_insert(&tree, "t - 8"); */
  /* btree_insert(&tree, "y - 10"); */
  /* btree_insert(&tree, "u - 9"); */
  /* btree_insert(&tree, "i - 3"); */
  /* btree_insert(&tree, "o - 4"); */
  /* btree_insert(&tree, "p - 5"); */
  print_preorder(tree);
  depth =  btree_depth(tree);
  printf("Depth of tree is %d\n", depth);
  btree_free(tree);
  return 0;
}

void print_preorder(BTree *tree) {
  if (tree == NULL) return;
  printf("%s\n", tree->str);
  print_preorder(tree->left);
  print_preorder(tree->right);
}
