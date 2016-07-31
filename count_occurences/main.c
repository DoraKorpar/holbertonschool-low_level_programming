#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_SIZE 10000

typedef struct List
{
	char *word;
	int num_occur;
	struct List *next;
} List;

typedef struct HashTable
{
	unsigned int size;
	List **array;
} HashTable;

/**
 * ht_create - creates a hashtable
 * 
 * Takes no parameters because simply allocating memory
 * for hashtable and array. Returns pointer to hashtable.
 */
HashTable *ht_create(void)
{
	HashTable *ht;
	unsigned int i;

	ht = NULL;
	if ( (ht = malloc(sizeof(HashTable))) == NULL )
		return (NULL);

	if ( (ht->array = malloc(sizeof(List *) * ARRAY_SIZE)) == NULL )
		return (NULL);

	for (i = 0; i < ARRAY_SIZE; i++) 
		ht->array[i] = NULL; /* initializes every array node to null */

	ht->size = ARRAY_SIZE;
	return (ht);
}

/**
 * hash - hash function optimized for string
 * @key : string that will be hashed
 *
 * Function generates hash based on string with bit shifting.
 * Then value is modulo'd by ARRAY_SIZE to ensure hash value
 * does not exceed number of possible array index.
 */ 
unsigned long
hash(const char *key)
{
	unsigned long hash = 5381;
	int c;

	while(c = *key++)
		hash = ((hash << 5) + hash) + c;

	hash %= ARRAY_SIZE;
	return (hash);
}

/**
 * ht_add - adds a node to the linked list array
 * @ht : pointer to hashtable
 * @word : word to be stored in linked list element
 *
 * Function checks if array element is empty (NULL). 
 * If no and words used to creates hashes are the same,
 * updates num_occur value for word.
 * If yes or no but words are different
 * creates new node and populates it.
 */
int ht_add(HashTable *ht, char *word, int *vocab_count)
{
	unsigned long h;
	List *l;
	
	h = hash(word);
	l = NULL;
	
	if (ht->array[h] != NULL && (strcmp(word, ht->array[h]->word) == 0))
	{
		ht->array[h]->num_occur++;
	}
	else
	{
		*vocab_count += 1; /* counts number of unique words */
		if ( (l = malloc(sizeof(List))) == NULL )
			return (1);
		if ( (l->word = strdup(word)) == NULL )
			return (1);
		l->num_occur = 1;
		l->next = ht->array[h]; /* new node is inserted at beginning of ll */
		ht->array[h] = l;
	}
	return (0);
}

/**
 * ht_print - prints contents of array from hashtable
 * @sm_array : condensed array of pointers to linked lists
 * @vocab_count : number of unique words
 *
 * Function simply loops through simple array and prints
 * each word and its number of occurences
 */ 
void ht_print(List **sm_array, int vocab_count)
{
	int i;

	i = 0;
	while (i < vocab_count)
		{
			printf("%s: %d\n", sm_array[i]->word, sm_array[i]->num_occur);
			i++;
		}
}

/**
 * comp_num - compares num_occur elements of linked lists
 *
 * Function used by qsort to sort sm_array. Sorts in order of
 * highest to lowest.
 */
int comp_num(void *word1, void *word2)
{
	return ((*(List**)word2)->num_occur - (*(List**)word1)->num_occur);
}

int main(__attribute__((unused))int argc, char **argv)
{
	FILE *fp;
	HashTable *ht;
	char word[45];
	int vocab_count;
	List **sm_array;
	int i, j;

	vocab_count = 0;
	if ( (fp = fopen(argv[1], "r")) == NULL )
		return (1);
	if ( (ht = ht_create()) == NULL )
		return (1);
		
	while (1)
	{
		fscanf(fp, "%s", word);
		if (feof(fp))
			break;
		if ( (ht_add(ht, word, &vocab_count)) == 1 )
			return (1);
	}
	printf("%d\n", vocab_count);

	sm_array = malloc(vocab_count * sizeof(List *));
	i = 0;
	j = 0;
	while (i < ARRAY_SIZE)
		{
			if (ht->array[i] != NULL)
				{
					sm_array[j] = ht->array[i];
					j++;
				}
			i++;
		}


	
	qsort(sm_array, vocab_count, sizeof(List *), (int (*)(const void *, const void *))comp_num);
	ht_print(sm_array, vocab_count);	
	fclose(fp);
	return (0);
}
