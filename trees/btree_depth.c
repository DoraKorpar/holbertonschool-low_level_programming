#include "tree.h"
#include "btree_funcs.h"
#include <stdio.h>

/**
 * btree_depth - finds depth of binary tree with helper func
 * @tree: pointer to first node of tree
 *
 * Calls function max_depth to recursively find longest branch
 * of binary tree. If the tree does not exist, return -1.
 */
int btree_depth(BTree *tree)
{
	int depth;

	if (tree == NULL)
		return (-1);
	else
		depth = max_depth(tree);
	return (depth);
}

/**
 * max_depth - recursively finds depth of longest branch
 * @tree: pointer to first node of tree
 *
 * At each node, function calls itself for left and 
 * right branch, ending when node is NULL, which first
 * returns 0. With each other return, 1 is added, which
 * serves at the counter.
 */
int max_depth(BTree *tree)
{
	int max_left;
	int max_right;

	if (tree == NULL) /* endpoint for recursion */
		return (0);
	max_left = max_depth(tree->left); 
	max_right = max_depth(tree->right);
	if (max_left > max_right) /* find which branch is longest */
		return (max_left + 1);
	else
		return (max_right + 1);
}
