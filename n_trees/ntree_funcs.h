#include "tree.h"

int ntree_insert(NTree **, char **, char *);
int traverse_tree(NTree **, NTree *, char **);
int add_node(NTree *, NTree *);
int path_exists(NTree *, char **);
NTree *node_exists(List *, char *);
void ntree_free(NTree *);
