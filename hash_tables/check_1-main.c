#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashtable.h"

/* The function ht_create is provided */
HashTable *ht_create(unsigned int);
/* The function ht_print is provided */
void ht_print(HashTable *);

int ht_put(HashTable *, const char *, const char *);

/*
 * This function will create a new HashTable
 * and put some pairs in it.
 *
 * Then the HashTable is printed to see if it worked.
 */
int basic(void)
{
  HashTable *hashtable;
  unsigned int size;

  size = 24;
  if ((hashtable = ht_create(size)) == NULL)
    return (1);
  if (ht_put(hashtable, "C", "Fun") != 0 ||
      ht_put(hashtable, "C++", "Awesome") != 0 ||
      ht_put(hashtable, "Java", "Easy") != 0 ||
      ht_put(hashtable, "Python", "Not as fun as C is") != 0 ||
      ht_put(hashtable, "JavaScript", "Fancy") != 0 ||
      ht_put(hashtable, "Assembly", "The answer") != 0)
    {
      printf("Yout function 'ht_put' does not work properly.\n");
      return (1);
    }
  ht_print(hashtable);
  return (0);
}

/*
 * This function has the same behaviour than 'basic'
 *
 * This time, we just reduce the size of the Hashtable
 * to maximize the collision risks
 * and see if it was properly handled
 */
int collisions(void)
{
  HashTable *hashtable;
  unsigned int size;

  size = 4;
  if ((hashtable = ht_create(size)) == NULL)
    return (1);
  if (ht_put(hashtable, "C", "Fun") != 0 ||
      ht_put(hashtable, "C++", "Awesome") != 0 ||
      ht_put(hashtable, "Java", "Easy") != 0 ||
      ht_put(hashtable, "Python", "Not as fun as C is") != 0 ||
      ht_put(hashtable, "JavaScript", "Fancy") != 0 ||
      ht_put(hashtable, "Assembly", "The answer") != 0)
    {
      printf("Yout function 'ht_put' does not work properly.\n");
      return (1);
    }
  ht_print(hashtable);
  return (0);
}

/*
 * This function will create a new HashTable
 * and put some pairs in it.
 *
 * After that it will put some pairs with a key
 * that is already on the HashTable.
 *
 * The value corresponding to the key should be updated
 * in the HashTable
 */
int existing_key(void)
{
  HashTable *hashtable;
  unsigned int size;

  size = 24;
  if ((hashtable = ht_create(size)) == NULL)
    return (1);
  if (ht_put(hashtable, "C", "Fun") != 0 ||
      ht_put(hashtable, "C++", "Awesome") != 0 ||
      ht_put(hashtable, "Java", "Easy") != 0 ||
      ht_put(hashtable, "Python", "Not as fun as C is") != 0 ||
      ht_put(hashtable, "JavaScript", "Fancy") != 0 ||
      ht_put(hashtable, "Assembly", "The answer") != 0)
    {
      printf("Yout function 'ht_put' does not work properly.\n");
      return (1);
    }
  ht_print(hashtable);
  printf("-----------------------------------------------\n");
  if (ht_put(hashtable, "C", "More than awesome !") != 0 ||
      ht_put(hashtable, "Assembly", "Everything") != 0)
    {
      printf("Yout function 'ht_put' does not work properly.\n");
      return (1);
    }
  ht_print(hashtable);
  return (0);
}

/*
 * This function will call ht_put
 * with only NULL pointers as parameters
 *
 * We don't need to check the return value.
 * If your function doesn't handle it
 * A Segmentation Fault will be raised
 */
int basic_errors(void)
{
  ht_put(NULL, NULL, NULL);
  return (0);
}

int main(int ac, char **av)
{
  if (ac < 2)
    {
      printf("Usage: %s basic|collisions|existing|errors\n", av[0]);
      return (1);
    }
  if (strcmp(av[1], "basic") == 0)
    return (basic());
  if (strcmp(av[1], "collisions") == 0)
    return (collisions());
  if (strcmp(av[1], "existing") == 0)
    return (existing_key());
  if (strcmp(av[1], "errors") == 0)
    return (basic_errors());
  return (1);
}
