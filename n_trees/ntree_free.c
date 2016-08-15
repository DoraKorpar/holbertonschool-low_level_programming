#include <stdlib.h>
#include "tree.h"
#include "ntree_funcs.h"

void ntree_free(NTree *tree)
{
	NTree *node;

	node = tree;
	if (tree == NULL)
		return ();
	free_node(node);
}

void free_node(NTree *node)
{
	List *list;
	List *temp;

	list = node->children;
	while (list != NULL)
	{
		temp = list->next;
		free_node(list->node);
		free(list);
		list = temp;
	}
	free(node->str);
	free(node);
}
