#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "ntree_funcs.h"

/**
 * path_exists - finds whether path exists in tree
 * @tree : pointer to first node of tree
 * @path : array of strings of nodes
 *
 * Function compares strings in array path to
 * node->str elements. If they match, next path
 * element compared to node->str elements at
 * next tree depth. If complete match found,
 * function returns 1.
 */
int path_exists(NTree *tree, char **path)
{
	int i, comp;
	NTree *node;
	List *children;

	i = 1;
	node = tree;
	comp = strcmp(node->str, path[0]);
	if (comp != 0)
		return (0);
	while (path[i] != NULL)
	{
		children = node->children;
		if (children == NULL)
			return (0);
		node = node_exists(children, path[i]);
		if (node == NULL)
			return (0);
		i++;
	}
	return (1);
}

/**
 * node_exists - finds whether node exists
 * @children : linked list of node
 * @path_str : string element of path array
 *
 * Function iterates through linked list at
 * specific tree depth. Compares strings of
 * nodes to path_str. If match found,
 * returns pointer to matching node.
 */
NTree *node_exists(List *children, char *path_str)
{
	int comp;

	while (children != NULL)
	{
		comp = strcmp(children->node->str, path_str);
		if (comp == 0)
			return (children->node);
		children = children->next;
	}
	return (NULL);
}
