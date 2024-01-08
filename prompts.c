#include "header.h"

/**
 * main - Code entry point.
 * @argc: Number of command-line arguments.
 * @argv: Array of strings containing command-line arguments.
 * @envp: Array of strings containing environment variables.
 *
 * Return: 0
 *
 */

int main(int argc, char **argv, char *envp[])
{
	char **command;
	char *input = NULL;
	(void)argc;
	(void)argv;

	while (1)
	{
		show_prompt();
		input = get_user_input();
		command = tokenize_input(input);
		execute_input(command, envp);
	}

	return (0);
}

/**
 * execute_input - Executes a given command.
 * @command: Array of strings representing commands and their arguments.
 * @envp: Array of strings containing environment variables.
 *
 * Return:Status of the executed command.
 *
 */

int execute_input(char **command, char *envp[])
{
	pid_t baby_pid;
	int status = 0;

	baby_pid = fork();

	if (baby_pid < 0)
	{
		perror("fork");
	}
	else if (baby_pid == 0)
	{
		if (execve(command[0], command, envp) == -1)
		{
			perror("execve");
			exit(0);
		}
	}
	else
	{
		waitpid(baby_pid, NULL, 0);
	}
	free(command);
	return (status);

}
