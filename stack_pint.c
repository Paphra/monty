#include "monty.h"

/**
 * pint_usage_fail - handle pint fail
 * @line_no: line number
 * Retuen: nothing
 */
void pint_usage_fail(ui line_no)
{
	free_global();
	fprintf(stderr, "L%u: can't pint, stack empty\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_pint - print the top most element
 * @stack: the stack
 * @line_number: the line no.
 * Return: nothing
 */
void stack_pint(stack_t **stack, ui line_number)
{
	if (*stack == NULL)
		pint_usage_fail(line_number);
	printf("%d\n", top->n);
}
