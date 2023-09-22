#include "monty.h"

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
