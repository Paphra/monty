#include "monty.h"

/**
 * swap_usage_fail - handle swap fail
 * @line_no: line number
 * Retuen: nothing
 */
void swap_usage_fail(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: can't swap, stack too short\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_swap - swap the two top most elements
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_swap(stack_t **stack, ui line_number)
{
	stack_t *second_last;

	if (*stack == NULL)
		swap_usage_fail(line_number);
	second_last = top->prev;
	if (second_last == NULL)
	{
		free_stack(stack);
		swap_usage_fail(line_number);
	}
	top->next = second_last;
	top->prev = second_last->prev;
	second_last->next = NULL;
	second_last->prev = top;
	top = second_last;

}
