#include "main.h"
#include <limits.h>

/**
 * _atoi -converts string to character
 * @s: string to convert
 *
 * Return: number
 *
 */

int _atoi(char *s)
{
	int i, num = 0, flag = 1, lbreak = 0, k = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '-' || s[i] == '+')
		{
			if (s[i] == '+' && (s[i + 1] >= '0' && s[i + 1] <= '9'))
				i++;
			else if (s[i] == '-')
			{
				k++;
				if (k % 2 != 0)
					flag = -1;
				else
					flag = 1; }
			while (s[i] >= '0' && s[i] <= '9')
			{
				num += s[i] - '0';
				if (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					num *= 10;
					if (num == 2147483640 && s[i + 1] == '8' && flag == -1)
						return (INT_MIN); }
				else if (!(s[i + 1] >= '0' && s[i + 1] <= '9'))
				{
					lbreak = 1;
					i++;
					break; }
				i++; }

		}
		if (lbreak == 1)
		{
			break;
		}
	}
	num *= flag;
	return (num);
}

/**
 * _strcat - appends 'src' string to 'dest' string
 * @dest: destination string
 * @src: soure string
 *
 * Return: pointer to resulting string
 *
 */

char *_strcat(char *dest, char *src)
{
	int i, k;
	for (i = 0; dest[i] != '\0'; i++)
	{
	}
	for (k = 0; src[k] != '\0'; k++)
	{
		dest[i] = src[k];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcpy - copies string pointed to by source including terminating null of byte to the buffer pointed to by dest
 * @dest: destination string
 * @src: source string
 *
 * Return: Dest
 *
 */

char *_strcpy(char *dest, char *src)
{
	int length;
	int i, j = 0;
	for (i = 0; src[i] != '\0'; i++)
	{}
	length = i + 1;
	for (j = 0; j < length; j++)
	{
		dest[j] = src[j];
	}
	return (dest);
}

/**
 * _strlen - returns length of string
 * @s: String array
 *
 * Return: always 0
 *
 */

int _strlen(char *s)
{
	int i;
	for (i = 0; s[i] != '\0'; i++)
	{}
	return (i);
}

/**
 * _strncmp - Compares two strings
 * @s1: First string
 * @s2: Second string
 * @n: number of chars to be compared
 *
 * Return: integer
 *
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i, diff = 0;
	for (i = 0; i < n; i++)
	{
		if (s1[i] == '\0' || s2[i] == '\0' ||
				s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			return (diff);
		}
	}
	return (0);
}
/**
 * _realloc - Reallocates memory block using malloc and free
 * @ptr: Pointer to previous memory
 * @old_size: Size of old allocated space
 * @new_size: Size of new to be allocated space
 *
 * Return: Pointer to new memory adress
 * 	  or NULL
 *
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i;
	char *p;
	if (ptr == NULL)
	{
	p = malloc(new_size * sizeof(*p));
	if (p == NULL)
		return (NULL);
	}
	else if (new_size == old_size)
	{
		return (ptr);
	}
	else if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size > old_size || new_size < old_size)
	{
		p = malloc(new_size * sizeof(*p));
		if (p == NULL)
		{
			free(p);
			return (NULL);
		}
		if (new_size < old_size)
		{
		for (i = 0; i < new_size; i++)
			p[i] = ((char *)ptr)[i];
		}
		else
		{
		for (i = 0; i < old_size; i++)
			p[i] = ((char *)ptr)[i];
		}
	}
	free(ptr);
	return (p);
}
