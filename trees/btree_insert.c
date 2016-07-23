#include "tree.h"
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

int traverse_tree(BTree *, BTree *);

int btree_insert(BTree **tree, char *data)
{
	BTree *node;
	BTree *temp;
	int ret;

	node = malloc(sizeof(BTree)); /* allocate space in memory for new node */
	if (node == NULL)
		return (1);
	node->str = strdup(data); /* puts copy of data string into the str member of struct node */
	if (node->str == NULL)
		return (1);
	node->left = NULL; /* the new node always inserted at end of tree, so points to NULL */
	node->right = NULL;
	if (*tree == NULL) /* means there are no previous nodes */
	  *tree = node;
	else
		{
			temp = *tree;
			ret = traverse_tree(temp, node); /* function will insert node at proper place */
			if (ret == 1)
				return (1);
		}
	return (0);
}

/**
 * traverse_tree - moves through tree recursively to place new node in correct place
 * @temp: pointer to first node of tree
 * @node: pointer to node to be inserted
 *
 * Compares str elements of both nodes and goes right or left based on outcome.
 * Recursively calls function to traverse through tree until next node pointed to
 * is NULL, where new node will be inserted.
 */
int traverse_tree(BTree *temp, BTree *node)
{
	int comp;

	comp = strcmp(temp->str, node->str); /* function outputs 0 if strings are equal, <0 if string2 is greater, and >0 if string2 is smaller */
	if (comp < 0 || comp == 0)
		{
			if (temp->right != NULL) /* continues looping through tree is next pointer is not NULL */
				{
					temp = temp->right;
					traverse_tree(temp, node);
				}
			else /* if next pointer is NULL, that means end of branch, and new node is inserted */
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
