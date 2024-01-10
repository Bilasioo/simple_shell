#include "Header.h"

/**
 *_eputs - function that prints an input string
 * @string: string to be printed
 *
 * Return: Nothing
 */

void _eputs(char *string)
{
	int j = 0;

	if (!string)
		return;
	while (string[j] != '\0')
	{
		_eputchar(string[j]);
		j++;
	}
}

/**
 * _eputchar - function that writes char d to stderr
 * @d: character to be written
 *
 * Return: On success 1.
 * 	  -1 on error and errno  printed
 *
 */
int _eputchar(char d)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(2, buf, j);
		j = 0;
	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 * _putfd - function that writes character d to  fd
 * @d:  character to be printed
 * @fd:  filedescriptor to write to or modify
 *
 * Return: On success 1.
 * 	   -1 on error is returned and the errno
 */

int _putfd(char d, int fd)
{
	static int j;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || j >= WRITE_BUF_SIZE)
	{
		write(fd, buf, j);
		j = 0;
	}
	if (d != BUF_FLUSH)
		buf[j++] = d;
	return (1);
}

/**
 *_putsfd -function that prints input string
 * @string: string to  print
 * @fd:  filedescriptor to write or modify
 *
 * Return: number of characters put
 *
 */

int _putsfd(char *string, int fd)
{
	int j = 0;

	if (!string)
		return (0);
	while (*string)
	{
		j += _putfd(*string++, fd);
	}
	return (j);
}
