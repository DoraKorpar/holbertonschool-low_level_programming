#include <stdlib.h>
#include "tree.h"
#include "ntree_funcs.h"

/**
 * ntree_free - frees ntree
 * @tree : pointer to first node of ntree
 *
 * Function checks if tree is empty,
 * then calls helper function to free tree.
 */
void ntree_free(NTree *tree)
{
	NTree *node;

	node = tree;
	if (tree == NULL)
		return;
	free_node(node);
}

/**
 * free_node - recursively frees ntree
 * @node : pointer to first node of tree
 *
 * Function uses recursion to free each
 * NTree node and children element of node.
 */
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
