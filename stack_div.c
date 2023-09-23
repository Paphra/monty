#include "monty.h"

/**
 * div_usage_fail - handle div fail
 * @line_no: line number
 * Return: nothing
 */
void div_usage_fail(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: can't div, stack too short\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * div_byzero - handle div by zero
 * @line_no: line number
 *
 * Return: nothing
 */
void div_byzero(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: division by zero\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_div - divide the two top most elements
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_div(stack_t **stack, ui line_number)
{
	stack_t *sec;

	if (*stack == NULL)
		div_usage_fail(line_number);
	sec = top->prev;
	if (sec == NULL)
	{
		free_stack(stack);
		div_usage_fail(line_number);
	}
	if (sec->n == 0)
	{
		free_stack(stack);
		div_byzero(line_number);
	}
	sec->next = NULL;
	sec->n = sec->n - top->n;
	free(top);
	top = sec;

}
