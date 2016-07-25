#include "tree.h"
#include "btree_funcs.h"
#include <stdio.h>

/**
 * array_to_btree - function takes array and creates a binary tree
 * @array: array is an array of strings, each of which will populate a
 * node of the tree
 *
 * Each string in the array will become the str element of the BTree
 * struct of the new node being created. The function btree_insert is
 * described in the eponymous file.
 */

BTree *array_to_btree(char **array)
{
	BTree *tree;
	int i;
	int ret;

	tree = NULL; /* initializing pointer to tree */
	i = 0;
	while (array[i]) /* only works if final element of array is NULL */
		{
			ret = btree_insert(&tree, array[i]);
			if (ret == 1)
				return NULL;
			i++;
		}
	return tree;
}
