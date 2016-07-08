#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

void ht_free(HashTable *hashtable)
{
  unsigned int i;
  List *tmp;
  List *tmp2;

  i = 0;
  
  printf("entering first loop\n");

  while (i < hashtable->size) {
    printf("assigning tmp\n");
    tmp = hashtable->array[i];

    if (tmp == NULL) {
      printf("this node is empty\n");
    }
    else {
      printf("entering second loop\n");
      while (tmp->next != NULL) {
	printf("assigning tmp2\n");
	tmp2 = tmp->next;
	printf("free key and value\n");
	free(tmp->key);
	free(tmp->value);
	printf("free tmp\n");
	free(tmp);
	printf("reassign tmp\n");
	tmp = tmp2;
	}
      printf("if only one node\n");
      if (tmp->next == NULL) {
	printf("freeing key and value\n");
	free(tmp->key);
	free(tmp->value);
	printf("free tmp\n");
	free(tmp);
      }
    }
    i++;
  }
  printf("free array\n");
  free(hashtable->array);
  printf("free hashtable\n");
  free(hashtable);
}
