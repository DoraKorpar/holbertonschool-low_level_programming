#include <string.h>
#include <stdlib.h>
#include "queue.h"

/**
 * pop_queue - enqueues first element of queue
 * @queue : pointer to first element of queue
 *
 * Function removes first element of queue by moving
 * *queue pointer to next element. First element is
 * then freed. Str is duplicated so it can be returned
 * for main function.
 */
char *pop_queue(Queue **queue)
{
	Queue *temp;
	char *str;

	if (*queue == NULL)
		return (NULL);
	temp = *queue;
	str = strdup(temp->str);
	*queue = temp->next; /* removes 1st element from queue */
	free(temp->str);
	free(temp);
	return (str);
}
