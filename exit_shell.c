#include "Header.h"

/**
 **_strncpy - functions that copies a string
 *@desti:  destination string
 *@srce: source string
 *@m: number of characters to be copied
 *
 *Return:  concat string
 *
 */

char *_strncpy(char *desti, char *srce, int m)
{
	int l, k;
	char *s = desti;

	l = 0;
	while (srce[l] != '\0' && l < m - 1)
	{
		desti[l] = srce[l];
		l++;
	}
	if (l < m)
	{
		k = l;
		while (k < m)
		{
			desti[k] = '\0';
			k++;
		}
	}
	return (s);
}

/**
 **_strncat - function that concatenates two strings
 *@dest: first string
 *@src: second string
 *@m: NUMBER of bytes to be used
 *
 *Return: concatenated string
 *
 */

char *_strncat(char *dest, char *src, int m)
{
	int l, k;
	char *s = dest;

	l = 0;
	k = 0;
	while (dest[l] != '\0')
		l++;
	while (src[k] != '\0' && k < m)
	{
		dest[l] = src[k];
		l++;
		k++;
	}
	if (k < m)
		dest[l] = '\0';
	return (s);
}

/**
 **_strchr - function that locates character in a string
 *@str: string that is parsed
 *@d: character
 *
 *Return: string pointer to memory area
 *
 */

char *_strchr(char *str, char d)
{
	do {
		if (*str == d)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
