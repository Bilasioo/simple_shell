#include "main.h"

/**
 * path_find - returns 2 dimension array with path variable
 * @env_vars: environment variables
 *
 * Return: NULL-terminated 2d array
 *
 */

char **path_find(char **env_vars)
{
    int index, count = 0;
    char **path_result;
    while (env_vars[count] != NULL)
    {
        count++;
    }
    path_result = malloc(sizeof(char *) * (count + 1));
    for (index = 0; index < count; index++)
    {
        path_result[index] = malloc(sizeof(char) * (_strlen(env_vars[index]) + 1));
        _strcpy(path_result[index], env_vars[index]);
    }
    path_result[index] = NULL;
    return path_result;
}
