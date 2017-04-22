#include "tree.h"
#include "btree_funcs.h"
#include <stdio.h>

void print_preorder(BTree *tree);

int main(void)
{
	char *array[] = {"c", "g", "a", "f", "s", "b", NULL};
	int i;
	BTree *tree;

	i = 0;
	while (array[i])
		{
			printf("%s\n", array[i]);
			i++;
		}
	tree = array_to_btree(array);
	print_preorder(tree);
	return (0);
}

void print_preorder(BTree *tree) {                                                                     
  if (tree == NULL) return;                                                                            
  printf("%s\n", tree->str);                                                                           
  print_preorder(tree->left);                                                                          
  print_preorder(tree->right);                                                                         
} 
