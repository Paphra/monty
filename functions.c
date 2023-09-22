#include "monty.h"

/**
 * make_instructions - make the instructions
 * @instruction: the instruction
 * Return: nothing
 */
void make_instructions(instruction_t **instructions)
{
	instruction_t *inst = *instructions;

	inst->opcode = "push";
	inst->f = *stack_push;
	inst++;

	inst->opcode = "pall";
        inst->f = *stack_pall;
	inst++;

}
