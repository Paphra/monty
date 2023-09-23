#include "monty.h"

/**
 * unknown_code - handle unknown codes
 * @stack: the stack
 * @line_no: line nunber
 * @code: the opcode
 * Return: nothing
 */
void unknown_code(stack_t **stack, ui line_no, char *code)
{
	free_global();
	free_stack(stack);
	fprintf(stderr, "L%u: unknown instruction %s\n", line_no, code);
	free(code);
	exit(EXIT_FAILURE);

}
/**
 * workers - initiate work on a line
 * @stack: pointer to the pointer of the head
 * @line_no: line nunber
 * Return: nothing
 */
void workers(stack_t **stack, ui line_no)
{
	char *code;
	instruction_t *tmp;
	int i;

	if (ntoks > 0)
	{
		code = strdup(tokens[0]);
		tmp = codes;
		for (i = 0; i < ncodes; i++)
		{
			if (strcmp(code, tmp->opcode) == 0)
			{
				tmp->f(stack, line_no);
				break;
			}
			tmp++;
		}
		if (i == ncodes)
			unknown_code(stack, line_no, code);
		else
			free(code);
	}
}
