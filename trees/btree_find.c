#include "tree.h"
#include "btree_funcs.h"
#include <string.h>
#include <stdio.h>

/**
 * btree_find - searches through binary tree and returns node whose str element
 * matches param
 * @tree: pointer to first node of tree
 * @str: string to find matching node
 *
 * btree_find ensures both parameters are not NULL, then calls the recursive
 * function find_node to go through the tree and find the node->str that
 * matches the string passed as parameter
 */

BTree *btree_find(BTree *tree, __attribute__((unused))char *str)
{
	BTree *found;
	BTree *temp;

 	temp = tree;
	printf("Before null check\n");
	if (tree == NULL || str[0] == '\0') /* ensures both params are not NULL */
		{
			printf("After null check\n");
			return (NULL);
		}
	else
		{
			printf("Before find_node called\n");
			found = find_node(temp, str); /* calls recursive function */
		}
	printf("Before btree_find return\n");
	return (found);
}

/**
 * find_node - function compares string of current node and string passed as
 * param to find match
 * @temp: pointer to current position in binary tree
 * @str: string to match
 *
 * This function uses recursion to check whether the string of the current node
 * matches that of the parameter string. If there is no match on comparison,
 * the pointer is moved to the next node of the tree, either left or right,
 * based on the comparison value of the two strings.
 * If the next node in the tree is NULL, that means there is no match to the
 * string, so the function returns NULL.
 */

BTree *find_node(BTree *temp, char *str)
{
	int comp;
	BTree *found;
	
	comp = strcmp(temp->str, str); /* compares str of node to string param */
	if (comp == 0)
		return (temp);
	else if (comp < 0) /* if value returned is <0, string2 greater than string1 */ 
		{
			if (temp->right != NULL) /* moves pointer to next node */
				{
					temp = temp->right;
					found = find_node(temp, str); /* assigns return of find_node to found */
				}
			else /* if next node is NULL, then there is no match */
				{
					printf("No match lalala segfault\n");
					return NULL;
				}
		}
	else if (comp > 0) /* string2 is less than string1, so to left of tree */
		{
			if (temp->left != NULL)
				{
					temp = temp->left;
					found = find_node(temp, str);
				}
			else /* again, if next node is NULL, then there is no match */
				{
					printf("No match so you get a segfault\n");
					return NULL;
				}
		}
 	return (found);
}
