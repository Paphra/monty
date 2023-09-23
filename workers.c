#include "monty.h"

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
		code = tokens[0];
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
		fprintf(stderr, "L%u: unknown instruction %s\n", line_no, code);
		exit(EXIT_FAILURE);
	}
}
