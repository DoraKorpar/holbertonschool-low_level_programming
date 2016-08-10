#include <stdlib.h>
#include <string.h>
#include "queue.h"

/**
 * push_queue - function adds new element to queue data structure
 * @queue : pointer to first element of queue
 * @str : string to be stored in new element
 *
 * Function creates new element with malloc, populates its
 * elements, then adds it to the end of the queue.
 */
int push_queue(Queue **queue, char *str)
{
	Queue *new_elmt;
	Queue *temp;

	new_elmt = malloc(sizeof(Queue));
	if (new_elmt == NULL)
		return (1);
	new_elmt->str = strdup(str);
	if (new_elmt->str == NULL)
		return (1);
	new_elmt->next = NULL;
	if (*queue == NULL)
		*queue = new_elmt; /* checks if queue is empty */
	else
	{
		temp = *queue;
		while (temp->next != NULL)
			temp = temp->next; /* finds end of queue */
		temp->next = new_elmt;
	}
	return (0);
}
