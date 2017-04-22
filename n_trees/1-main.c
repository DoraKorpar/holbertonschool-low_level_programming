#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

int path_exists(NTree *, char **);

int ntree_insert(NTree **, char **, char *);
void ntree_free(NTree *);
char **string_split(const char *, char);
void free_str_array(char **);

int main(void)
{
	NTree *tree;
	char **array;

	tree = NULL;
	ntree_insert(&tree, NULL, "/");
	ntree_insert(&tree, (array = string_split("/", ',')), "home");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home", ' ')), "ubuntu");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Documents");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Download");
	free_str_array(array);
	ntree_insert(&tree, (array = string_split("/ home ubuntu", ' ')), "Public");
	free_str_array(array);

	printf("Path=[%s], present:%d\n", "/ home", path_exists(tree, (array = string_split("/ home", ' '))));
	free_str_array(array);
	printf("Path=[%s], present:%d\n", "/ home ubuntu", path_exists(tree, (array = string_split("/ home ubuntu", ' '))));
	free_str_array(array);
	printf("Path=[%s], present:%d\n", "/ home ubuntu Download", path_exists(tree, (array = string_split("/ home ubuntu Download", ' '))));
	free_str_array(array);
	printf("Path=[%s], present:%d\n", "/ home student", path_exists(tree, (array = string_split("/ home student", ' '))));
	free_str_array(array);
	printf("Path=[%s], present:%d\n", "/ home ubuntu Public file", path_exists(tree, (array = string_split("/ home ubuntu Public file", ' '))));
	free_str_array(array);

	ntree_free(tree);
	return (0);
}
