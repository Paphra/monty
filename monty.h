#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ui unsigned int

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
	void (*f)(stack_t **stack, ui line_number);
} instruction_t;

/* Globals */
instruction_t *codes;
int ncodes, ntoks, data;
size_t line_no;
char *line, **tokens;
stack_t *top;
FILE *file;

/* Prototypes */
void check_usage(int argc);
void check_file_open(FILE *file, char *file_path);
void check_malloc(void *pointer);
void malloc_fail_frees(void);
int only_numbers(char *str);

void make_instructions(void);

int count_tokens(char **tokens);
char **line_tokens(void);
void free_tokens(void);
void free_stack(stack_t **stack);
void free_global(void);

void stack_push(stack_t **stack, ui line_number);
void stack_pall(stack_t **stack, ui line_number);
void stack_pop(stack_t **stack, ui line_number);
void stack_pint(stack_t **stack, ui line_number);
void stack_swap(stack_t **stack, ui line_number);
void stack_nop(stack_t **stack, ui line_number);
void stack_add(stack_t **stack, ui line_number);

/* advanved */
void stack_sub(stack_t **stack, ui line_number);
void stack_div(stack_t **stack, ui line_number);
void stack_mul(stack_t **stack, ui line_number);
void stack_mod(stack_t **stack, ui line_number);
void stack_pchar(stack_t **stack, ui line_number);
void stack_pstr(stack_t **stack, ui line_number);
void stack_rotl(stack_t **stack, ui line_number);
void stack_rotr(stack_t **stack, ui line_number);
void stack_stack(stack_t **stack, ui line_number);
void stack_queue(stack_t **stack, ui line_number);

void workers(stack_t **stack, ui line_no);


#endif /* #ifndef MONTY_H */
