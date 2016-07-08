#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

void ht_free(HashTable *hashtable)
{
  unsigned int i;
  List *tmp;
  List *tmp2;

  i = 0;
  while (i < hashtable->size) {
    tmp = hashtable->array[i];
    /* if element of array is empty, do nothing */
    if (tmp == NULL) {
    }
    else {
      while (tmp->next != NULL) {
	/* goes through linked list and frees all parts */
	tmp2 = tmp->next;
	free(tmp->key);
	free(tmp->value);
	free(tmp);
	tmp = tmp2;
      }
      if (tmp->next == NULL) {
	/* frees last node in linked list or if there's only single node */
	free(tmp->key);
	free(tmp->value);
	free(tmp);
      }
    }
    i++;
  }
  free(hashtable->array);
  free(hashtable);
}
