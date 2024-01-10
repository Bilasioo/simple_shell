#include "main.h"

/**
 * get_user_input - reads user input from std input
 *
 * Return: number of characters read on succes
 * 	   otherwise -1
 *
 */
char *get_user_input(void)
{
	char *cmd = NULL;
	size_t size = 0;
	ssize_t read;

	read = getline(&cmd, &size, stdin);

	if (read == -1)
	{
		perror("getline");
		return (NULL);
	}

	return (cmd);

}
