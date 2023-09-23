#include "monty.h"

/**
 * push_usage_fail - exit on fail for usage
 * @line_no: line number
 * Return: nothing
 */
void push_usage_fail(int line_no)
{
	free_global();
	fprintf(stderr, "L%u: usage: push integer\n", line_no);
	exit(EXIT_FAILURE);
}

/**
 * stack_push - push an integer to the stack
 * @stack: the stack to push
 * @line_number: the line number from the file
 * Return: nothing
 */
void stack_push(stack_t **stack, ui line_number)
{
	stack_t *item, *new_item;

	if (ntoks < 2 || only_numbers(tokens[1]) == 0)
	{
		free_stack(stack);
		push_usage_fail(line_number);
	}
	data = atoi(tokens[1]);
	item = *stack;
	if (item == NULL)
	{
		item = (stack_t *)malloc(sizeof(stack_t));
		if (item == NULL)
		{
			free_stack(stack);
			malloc_fail_frees();
		}
		item->next = NULL;
		item->prev = NULL;
		item->n = data;
		*stack = item;
		top = item;
	} else
	{
		while (item->next != NULL)
			item = item->next;
		new_item = (stack_t *)malloc(sizeof(stack_t));
		new_item->next = NULL;
		new_item->prev = item;
		new_item->n = data;
		item->next = new_item;
		top = new_item;
	}
}
