#include "main.h"

/**
 * _exiting - exiting shell
 * @cmd: struct pointer
 *
 * Return: void
 *
 */

void _exiting(input_t *cmd)
{
    int status;
    if (_strncmp(cmd->argv[0], "exit", 4) == 0)
    {
        if (cmd->argv[1])
        {
            status = _atoi(cmd->argv[1]);
            if (status < 0)
            {
                write(STDERR_FILENO, cmd->argv[0], _strlen(cmd->argv[0]));
                perror(": 1: exit: Illegal number: ");
                write(STDERR_FILENO, cmd->argv[1], _strlen(cmd->argv[1]));
                status = 2;
            }
            if (cmd->pathFlag == 0)
                free(cmd->path);
            free_struct(cmd);
            free(cmd);
            exit(status);
        }
        if (cmd->pathFlag == 0)
            free(cmd->path);
        free_struct(cmd);
        free(cmd);
        exit(EXIT_SUCCESS);
    }
}

/**
 * _env - prints current environment
 * @cmd: pointer to a structure
 * @env_p: pointer to environment variables
 *
 * Return: void
 *
 */

void _env(input_t *cmd, char **env_p)
{
    int i = 0;
    (void)cmd;
    (void)env_p;
    while (environ[i] != NULL)
    {
        if (environ[i][0] == '_')
            break;
        write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
        write(2, "\n", 1);
        i++;
    }
}

/**
 * _chdir - changes current directory
 * @cmd: pointer to a structure
 *
 * Return: void
 *
 */

void _chdir(input_t *cmd)
{
    if (chdir(cmd->argv[1]) != 0)
        perror("Error: chdir failed\n");
}

