#include "hashtable.h"
#include <stdlib.h>
#include <stdio.h>

HashTable *ht_create(unsigned int size)
{
  HashTable *ht;
  unsigned int i;
  
  ht = NULL;
  /* allocate mem to hashtable array */
  ht = malloc(sizeof(HashTable));
  if (ht == NULL) {
    return NULL;
  }

  /* allocate memory for an array of pointers to list */
  ht->array = malloc(sizeof(List *) * size);
  if (ht->array == NULL) {
    return NULL;
  }

  /* initialize each element of array to null */
  for (i = 0; i < size; i++) {
    ht->array[i] = NULL;
  }
  
  ht->size = size;
  
  return ht;
}
