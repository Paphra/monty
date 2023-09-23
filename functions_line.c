#include "monty.h"

/**
 * count_tokens_line - count tokens
 * @str: the string (line)
 * @delim: delimeter
 * Return: number of tokens
 */
int count_tokens_line(char *str, char *delim)
{
	int count = 0;
	char *strcp, *tmp;


	strcp = strdup(str);
	tmp = strtok(strcp, delim);
	while (tmp)
	{
		count++;
		tmp = strtok(NULL, delim);
	}

	free(strcp);
	/*free(tmp);*/
	return (count);
}

/**
 * line_tokens - get the tokens from a line
 * Return: pointer to the arrayof tokens
 */
char **line_tokens(void)
{
	char **tokens, *line_tmp, *tmp;
	int ntoks = 0, i;
	char *delim = " \n";

	line_tmp = strdup(line);
	ntoks = count_tokens_line(line_tmp, delim);
	tokens = (char **)malloc(sizeof(char *) * (ntoks + 1));
	tmp = strtok(line_tmp, delim);
	for (i = 0; i < ntoks && tmp; i++)
	{
		tokens[i] = strdup(tmp);
		tmp = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	free(tmp);
	free(line_tmp);
	return (tokens);
}

/**
 * free_tokens - free tokens array
 * Return: nothing
 */
void free_tokens(void)
{
	int i;
	char *tmp;

	for (i = 0; i < ntoks; i++)
	{
		tmp = tokens[i];
		free(tmp);
	}
	free(tokens);
}

/**
 * count_tokens - count tokens frok array
 * @tokens: tokens array
 * Return: number of tokens
 */
int count_tokens(char **tokens)
{
	int count = 0;

	while (tokens[count] != NULL)
		count++;

	return (count);
}
