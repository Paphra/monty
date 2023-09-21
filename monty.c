#include "monty.h"
#include <unistd.h>
/**
 * main - the starting point of the Monty Interpreter
 * @argc: the count of arguments to the interpretor
 * @argv: the vector array of arguments
 * Return: 0 - success, else Failed
 */
int main(int argc, char **argv)
{
	char *file_path, *line;
	FILE *file;
	ssize_t line_size;
	stack_t *stack;
	instruction_t *inst;
	size_t line_bfsize = 0, line_count = 0;

	check_usage(argc);
	file_path = argv[1];
	file = fopen(file_path, "r");
	check_file_open(file, file_path);
	inst = make_instructions();

	line_size = getline(&line, &line_bfsize, file);
	while (line_size >= 0)
	{
		line_count++;
		printf("Line[%ld]: %s", line_count, line);
		line_size = getline(&line, &line_bfsize, file);
	}

	free(line);
	line = NULL;
	fclose(file);

	return (0);
}
