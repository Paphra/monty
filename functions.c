#include "monty.h"
#include <ctype.h>

/**
 * make_instructions - make the instructions
 * Return: nothing
 */
void make_instructions(void)
{
	instruction_t *code;

	ncodes = 2;
	codes = (instruction_t *)malloc(sizeof(instruction_t) * ncodes);
	if (codes == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	code = codes;
	code->opcode = "push";
	code->f = *stack_push;
	code++;

	code->opcode = "pall";
	code->f = *stack_pall;
}

/**
 * free_stack - frees a stack list
 * @stack: the stack to free
 * Return: nothing
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp, *item;

	if (*stack != NULL)
	{
		item = *stack;
		while (item)
		{
			tmp = item->next;
			free(item);
			item = tmp;
		}
	}
}

/**
 * free_global - free all global variables
 * Return: nothing
 */
void free_global(void)
{
	free(line);
	free(codes);
	free_tokens();
}

/**
 * only_numbers - checks whether string only contains nos.
 * @str: the string
 * Return: 0, if no and 1 is yes
 */
int only_numbers(char *str)
{
	while (*str)
	{
		if (!isdigit((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
