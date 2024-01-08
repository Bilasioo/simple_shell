#include "Header.h"

/**
 * tokenize_input - Function to tokenize an input.
 * @input: The input string to be tokenized..
 *
 * Return: array of the tokens
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
	token = strtok(temp, " \n");
	if (token == NULL)
	{
		free(temp);
		return (NULL);
	}
	while (token != NULL)
	{
		counter++;
		token = strtok(NULL, " \n");
	}
	free(temp);
	buff = malloc(sizeof(char *) * (counter + 1));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}

	token = strtok(input, " \n");
	while (token != NULL)
	{
		buff[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	buff[i] = NULL;
	return (buff);

}

