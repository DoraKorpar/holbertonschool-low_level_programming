#include "tree.h"

int btree_insert(BTree **, char *);
int traverse_tree(BTree *, BTree *);
BTree *btree_find(BTree *, char *);
BTree *find_node(BTree *, char *);
BTree *array_to_btree(char **);
void btree_free(BTree *);
void free_node(BTree *);
