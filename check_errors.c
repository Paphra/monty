#include "monty.h"

/**
 * check_usage - checks whether the usage is fine
 * @argc: number of arguments
 * Return: nothing
 */
void check_usage(int argc)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
}

/**
 * check_file_open - checks to see if the file has been opened
 * @file: the file pointer
 * @file_path: the location of the file
 * Return: nothing
 */
void check_file_open(FILE *file, char *file_path)
{
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
}
