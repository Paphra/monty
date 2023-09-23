#include "monty.h"

/**
 * push_usage_fail - exit on fail for usage
 * @line_no: line number
 * Return: nothing
 */
void push_usage_fail(int line_no)
{
	free(line);
	free(codes);
	free_tokens();
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
	int data;
	stack_t *item, *new_item;
	char *data_str;

	if (ntoks < 2)
	{
		free_stack(stack);
		push_usage_fail(line_number);
	}
	data_str = tokens[1];
	data = atoi(data_str);
	if (data == 0 && strcmp(data_str, "0") != 0)
	{
		free_stack(stack);
		push_usage_fail(line_number);
	}
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
