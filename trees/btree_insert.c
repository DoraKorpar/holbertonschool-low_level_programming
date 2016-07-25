#include "tree.h"
#include "btree_funcs.h"
#include <stdlib.h>
#include <string.h>

/**
 * btree_insert - inserts a new node into a binary tree
 * @tree: pointer to a pointer to a binary tree node
 * @data: string that will be in the new node
 *
 * If tree is NULL, btree_insert creates a new binary tree.
 * If tree is not NULL, btree_inserts a node into the tree
 * at the appropriate place. Place is determined by comparing the
 * data elements of nodes. Lower elements are to the left.
 * Greater or equal elements are to the right.
 */

int btree_insert(BTree **tree, char *data)
{
	BTree *node;
	BTree *temp;
	int ret;

	node = malloc(sizeof(BTree)); /* allocate space in mem for new node */
	if (node == NULL)
		return (1);
	node->str = strdup(data); /* puts copy of data string into the str */
	if (node->str == NULL)
		return (1);
	node->left = NULL; /* node inserted at end of tree, points to NULL */
	node->right = NULL;
	if (*tree == NULL) /* means there are no previous nodes */
		*tree = node;
	else
		{
			temp = *tree;
			ret = traverse_tree(temp, node); /* insert node */
			if (ret == 1)
				return (1);
		}
	return (0);
}

/**
 * traverse_tree - moves thru tree recursively to put new node in correct place
 * @temp: pointer to first node of tree
 * @node: pointer to node to be inserted
 *
 * Compares str elements of both nodes with strcmp and goes right or left based
 * on outcome. strcmp returns 0 if strings are equal, <0 if 2nd string is
 * greater, and >0 if second string is smaller.
 * Recursively calls function to traverse through tree until next node pointed
 * to is NULL, where new node will be inserted.
 */
int traverse_tree(BTree *temp, BTree *node)
{
	int comp;

	comp = strcmp(temp->str, node->str); /* determine where to put node */
	if (comp < 0 || comp == 0)
	{
		if (temp->right != NULL)
		{
			temp = temp->right;
			traverse_tree(temp, node);
		}
		else /* if nxt ptr NULL means end of branch */
		{
			temp->right = node;
			node->right = NULL;
			node->left = NULL;
		}
	}
	else /* same as previous comments, just on left of tree */
	{
		if (temp->left != NULL)
		{
			temp = temp->left;
			traverse_tree(temp, node);
		}
		else
		{
			temp->left = node;
			node->right = NULL;
			node->left = NULL;
		}
	}
	return (0);
}
