#include "monty.h"

/**
 * make_instructions - make the instructions
 * Return: nothing
 */
void make_instructions()
{
	instruction_t *tmp;
	codes_count = 2;

	codes = malloc(sizeof(instruction_t *) * codes_count);
	if (codes == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	tmp = malloc(sizeof(instruction_t));
	if (tmp == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	*codes = tmp;
	tmp->opcode = "push";
	tmp->f = *stack_push;
	tmp++;

	tmp->opcode = "pall";
        tmp->f = *stack_pall;
}

/**
 * free_instructions - free the instructions array
 * Return: nothing
 */
void free_instructions(void)
{

}
