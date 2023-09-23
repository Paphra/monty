#include "monty.h"

/**
 * add_usage_fail - handle swap fail
 * @line_no: line number
 * Return: nothing
 */
void add_usage_fail(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: can't add, stack too short\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_add - add the two top most elements
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_add(stack_t **stack, ui line_number)
{
	stack_t *sec;

	if (*stack == NULL)
		add_usage_fail(line_number);
	sec = top->prev;
	if (sec == NULL)
	{
		free_stack(stack);
		add_usage_fail(line_number);
	}
	sec->next = NULL;
	sec->n = sec->n + top->n;
	free(top);
	top = sec;

}
