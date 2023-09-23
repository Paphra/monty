#include "monty.h"

/**
 * stack_pall - print all elements of the stack
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_pall(stack_t **stack, ui line_number)
{
	stack_t *item;

	(void) line_number;
	if (*stack != NULL)
	{
		item = top;
		while (item != NULL)
		{
			printf("%d\n", item->n);
			item = item->prev;
		}
	}
}
