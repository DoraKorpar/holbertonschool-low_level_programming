#include <stdio.h>
#include <string.h>
#include "tree.h"
#include "ntree_funcs.h"

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
