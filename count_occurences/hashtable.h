#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

typedef struct List
{
	char *key;
	int value;
	struct List *next;
} List;

typedef struct HashTable
{
	unsigned int size;
	List **array;
} HashTable;

#endif
