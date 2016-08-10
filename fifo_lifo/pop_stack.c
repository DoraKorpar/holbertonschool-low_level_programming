#include <string.h>
#include <stdlib.h>
#include "stack.h"

/**
 * pop_stack - removes top element of stack
 * @stack : pointer to first/top element of stack
 *
 * Function removes first element of stack by
 * moving *stack pointer to next element. First
 * element is then freed. Str is duplicated so it can
 * be returned to main function.
 */
char *pop_stack(Stack **stack)
{
	Stack *temp;
	char *str;

	if (*stack == NULL)
		return (NULL);
	temp = *stack;
	str = strdup(temp->str);
	*stack = temp->next; /*removes 1st element from stack */
	free(temp->str);
	free(temp);
	return (str);
}
