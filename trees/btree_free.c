#include "tree.h"
#include "btree_funcs.h"
#include <stdlib.h>

/**
 * btree_free - calls another func to recursively free binary tree
 * @tree: pointer to first node of binary tree to be freed
 *
 * Function first checks to make sure tree is not empty, then
 * calls function free_node to actually free the nodes.
 */

void btree_free(BTree *tree)
{
	BTree *node;

	node = tree;
	if (tree == NULL) /* checks if there is anything to free */
		return;
	free_node(node); /* calls recursive function */
}

/**
 * free_node - uses recursion to free all allocated memory in tree
 * @node: pointer to first node of tree passed from btree_free
 *
 * Function frees the str element of each node because that was
 * malloc'd through the strdup func used in btree_insert. Then it
 * recursively frees each element to the left and right. If the node
 * is NULL, meaning the end of a branch, the function returns.
 */

void free_node(BTree *node)
{
	if (node == NULL) /* stop once end of branch is reached */
		return;
	free(node->str);
	free_node(node->right);
	free_node(node->left);
	free(node);
}
