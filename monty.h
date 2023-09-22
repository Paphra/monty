#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Globals */
instruction_t *codes;
int top, bottom, ncodes;
size_t line_no;
char *line;

/* Prototypes */
void check_usage(int argc);
void check_file_open(FILE *file, char *file_path);
void check_malloc(void *pointer);

void make_instructions(void);


void stack_push(stack_t **stack, unsigned int line_number);
void stack_pall(stack_t **stack, unsigned int line_number);
void stack_pop(stack_t **stack, unsigned int line_number);
void stack_pint(stack_t **stack, unsigned int line_number);
void stack_swap(stack_t **stack, unsigned int line_number);
void stack_nop(stack_t **stack, unsigned int line_number);
void stack_add(stack_t **stack, unsigned int line_number);

#endif /* #ifndef MONTY_H */
