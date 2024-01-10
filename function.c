#include "main.h"

/**
 * tokenize_input - function to tokenize input
 * @input: input string to be tokenized
 *
 * Return: array of tokens
 *
 */

char **tokenize_input(char *input)
{
	char *token;
	char *temp = NULL;
	char **buff;
	int i = 0, counter = 0;
	if (!input)
		return (NULL);
	temp = strdup(input);
	token = strtok(temp, " \n\t");
	if (token == NULL)
	{
		free(temp);
		return (NULL);
	}
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, " \n\t");
	}
	free(temp);
	buff = malloc(sizeof(char *) * (counter + 1));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	token = strtok(input, " \n\t");
	while (token != NULL)
	{
		buff[i] = token;
		token = strtok(NULL, " \n\t");
		i++;
	}
	buff[i] = NULL;
	return (buff);
}
