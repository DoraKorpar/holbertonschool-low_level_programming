#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "ntree_funcs.h"

/**
 * ntree_insert - creates and inserts new node of ntree
 * @tree : pointer to first node of tree
 * @parents : array of strings of parent nodes
 * @data : string to be stored in new node
 *
 * Function allocates memory to create new node. If
 * tree is empty, inserts new node as first node.
 * Otherwise, calls traverse_tree to find correct
 * location for new node based on parents array.
 */
int ntree_insert(NTree **tree, char **parents, char *data)
{
	NTree *node;

	node = malloc(sizeof(NTree));
	if (node == NULL)
		return (1);
	node->str = strdup(data);
	node->children = NULL;
	if (*tree == NULL)
		*tree = node; /* if new node is first node */
	else
	{
		if ((traverse_tree(tree, node, parents)) == 1)
			return (1);
	}
	return (0);
}

/**
 * traverse_tree - finds correct location for new node
 * @tree : pointer to first node of tree
 * @node : pointer to new node
 * @parents : array of strings of parent nodes
 *
 * Parents array contains strings held in each parent
 * node of new node to be inserted. Function compares
 * node->str with elements of parent to determine
 * where new node belongs, then calls add_node to
 * insert node.
 */
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

/**
 * add_node - inserts new node into ntree
 * @current : pointer to last parent node
 * @node : pointer to new node
 *
 * Function creates struct List node to
 * populate current's children element.
 * New node is then added to List's node
 * element. If children element is not
 * empty, new linked list node is added
 * to beginnig of list.
 */
int add_node(NTree *current, NTree *node)
{
	List *list;

	list = malloc(sizeof(List));
	if (list == NULL)
		return (1);
	list->node = node;
	list->next = NULL;
	if (current->children == NULL)
		current->children = list;
	else
	{
		list->next = current->children;
		current->children = list;
	}
	return (0);
}
