#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "ntree_funcs.h"

int ntree_insert(NTree **tree, char **parents, char *data)
{
	NTree *node;

	node = malloc(sizeof(NTree));
	if (node == NULL)
		return (1);
	node->str = strdup(data);
	node->children = NULL;
	if (*tree == NULL)
		*tree = node;
	else
	{
		if ((traverse_tree(tree, node, parents)) == 1)
			return (1);
	}
	return (0);
}

int traverse_tree(NTree **tree, NTree *node, char **parents)
{
	NTree *current;
	List *list;
	int i, comp, comp2;

	i = 1;
	current = *tree;
	list = current->children;
	comp = strcmp(parents[0], current->str);
	if (comp != 0)
		return (1);
	while (parents[i] != NULL)
	{
		comp2 = strcmp(parents[i], list->node->str);
		if (comp2 != 0)
			list = list->next;
		else
		{
			current = list->node;
			list = current->children;
			i++;
		}
	}
	if ((add_node(current, node)) == 1)
		return (1);
	return (0);
}

int add_node(NTree *current, NTree *node)
{
	List *list2;

	list2 = malloc(sizeof(List));
	if (list2 == NULL)
		return (1);
	list2->node = node;
	list2->next = NULL;
	if (current->children == NULL)
		current->children = list2;
	else
	{
		list2->next = current->children;
		current->children = list2;
	}
	return (0);
}
