#include "hashtable.h"
#include <stdlib.h>
#include <string.h>

int add_node(List **, const char*, const char *);
unsigned int hash(const char *key, unsigned int size);

int ht_put(HashTable *hashtable, const char *key, const char *value)
{
  unsigned int h;

  h = hash(key, hashtable->size);

  /* if array is not empty, create a new node in the linked list */
  if ( (add_node(&hashtable->array[h], key, value) ) == 1) {
      return (1);
  }

  return (0);
}

int add_node(List **list, const char *key, const char *value)
{
  List *l;

  l = NULL;
  /* allocate space for new node */
  l = malloc(sizeof(List));
  if (l == NULL) {
    return (1);
  }

  /* populate new node */
  if ( (l->key = strdup(key)) == NULL) {
    return (1);
  }
  if ( (l->value = strdup(value)) == NULL) {
    return (1);
  }
  
  /* adds node to the beginning of list */
  l->next = *list;
  /* now list pointer points to new node */
  *list = l;

  return (0);
}
