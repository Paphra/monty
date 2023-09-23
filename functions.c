#include "monty.h"
#include <ctype.h>

/**
 * more_codes - make more instructions
 * @code: the last code
 * Return: nothing
 */
void more_codes(instruction_t *code)
{
	(void) code;
}

/**
 * make_instructions - make the instructions
 * Return: nothing
 */
void make_instructions(void)
{
	instruction_t *code;

	ncodes = 9;
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
	code++;
	code->opcode = "pint";
	code->f = *stack_pint;
	code++;
	code->opcode = "pop";
	code->f = *stack_pop;
	code++;
	code->opcode = "swap";
	code->f = *stack_swap;
	code++;
	code->opcode = "add";
	code->f = *stack_add;
	code++;
	code->opcode = "nop";
	code->f = *stack_nop;
	code++;
	code->opcode = "sub";
	code->f = *stack_sub;
	code++;
	code->opcode = "div";
	code->f = *stack_div;
	more_codes(code);
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
	line = NULL;
	free(codes);
	free_tokens();
	fclose(file);
}

/**
 * only_numbers - checks whether string only contains nos.
 * @str: the string
 * Return: 0, if no and 1 is yes
 */
int only_numbers(char *str)
{
	int check = 0;

	while (*str)
	{
		check = isdigit((unsigned char)*str);
		if (!check  && *str != '+' && *str != '-')
			return (0);
		str++;
	}
	return (1);
}
