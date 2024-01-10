#include "Header.h"

/**
 * _strlen - function that prints length of a string
 * @r:  string whose length is to be printed
 *
 * Return: int length of string
 *
 */

int _strlen(char *r)
{
	int j = 0;

	if (!r)
		return (0);

	while (*r++)
		j++;
	return (j);
}

/**
 * starts_with - function that checks if needle begins with haystack
 * @haystack: string to be searched
 * @needle: substring to be sought
 *
 * Return: address of next character of haystack
 * 	   NULL if otherwise
 *
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - function that concatenates destination and source buffers
 * @desti: destination buffer
 * @srce:  source buffer
 *
 * Return: ptr to destination buffer
 *
 */

char *_strcat(char *desti, char *srce)
{
	char *p = desti;

	while (*desti)
		desti++;
	while (*srce)
		*desti++ = *srce++;
	*desti = *srce;
	return (p);
}
/**
 * _strcmp -  function that compares two strings
 * @str1:  first string
 * @str2:  second string
 *
 * Return: negative if str1 < str2,
 *	positive if str1 > str2,
 *	zero if str1 == str2
 *
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	if (*str1 == *str2)
		return (0);
	else
		return (*str1 < *str2 ? -1 : 1);
}

