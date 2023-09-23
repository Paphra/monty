#include "monty.h"

/**
 * pop_usage_fail - handle pint fail
 * @line_no: line number
 * Retuen: nothing
 */
void pop_usage_fail(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: can't pop an empty stack\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_pop - remove top most element
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_pop(stack_t **stack, ui line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
		pop_usage_fail(line_number);
	if (top->prev == NULL)
	{
		free(top);
		*stack = NULL;
	} else
	{
		tmp = top->prev;
		free(top);
		tmp->next = NULL;
		top = tmp;
	}
}
