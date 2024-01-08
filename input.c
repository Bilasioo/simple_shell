#include "Header.h"

/**
 * get_user_input - Reads/gets user input from standard input
 *
 * Return:Number of characters read upon success
 * 	  Otherwise -1
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
