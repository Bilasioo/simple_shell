#include "Header.h"

/**
 * bfree - function that frees a pointer and NULLify the address
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed,
 *	   0 otherwise
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
