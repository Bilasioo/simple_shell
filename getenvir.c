#include "main.h"

/**
 * _getenv - gets environment variable
 * @variable_name: variable name
 *
 * Return: string with value of environment variable
 *
 */

char *_getenv(const char *variable_name)
{
    int i, length = 0;
    char *result = NULL;
    length = _strlen((char *)variable_name);
    for (i = 0; environ[i] != NULL; i++)
    {
        if (_strncmp((char *)variable_name, environ[i], length) == 0)
        {
            return environ[i];
        }
    }

    return result;
}
