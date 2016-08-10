#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
 * push_stack - func adds new element to stack data structure
 * @stack : pointer to first element of stack
 * @str : string to be stored in new element
 *
 * Fuction allocates memory for new element, populates element,
 * and adds it to top of stack
 */
int push_stack(Stack **stack, char *str)
{
	Stack *new_elmt;

	new_elmt = malloc(sizeof(Stack));
	if (new_elmt == NULL)
		return (1);
	new_elmt->str = strdup(str);
	if (new_elmt->str == NULL)
		return (1);
	if (*stack == NULL) /* checks if stack is empty */
		new_elmt->next = NULL;
	else
		new_elmt->next = *stack;
	*stack = new_elmt; /* sets new element at top of stack */
	return (0);
}
