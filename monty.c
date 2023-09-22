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
	char *file_path;
	FILE *file;
	ssize_t line_size;
	stack_t **stack;
	size_t line_bfsize = 0, line_no = 0;

	line = NULL;
	check_usage(argc);
	file_path = argv[1];
	file = fopen(file_path, "r");
	check_file_open(file, file_path);
	make_instructions();
	(void) stack;

	line_size = getline(&line, &line_bfsize, file);
	while (line_size >= 0)
	{
		line_no++;
		printf("Line[%ld]: %s", line_no, line);
		line_size = getline(&line, &line_bfsize, file);
	}

	free(line);
	line = NULL;
	free(codes);
	fclose(file);

	return (0);
}
