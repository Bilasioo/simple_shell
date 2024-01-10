#include "Header.h"

/**
 * main - is the entry point of the code
 * @argc: number of command line arguments.
 * @argv: array of strings containing command line arguments
 * @envp: array of strings containing environment variables
 * Return: 0
 *
 */

int main(int argc, char **argv, char *envp[])
{
	char *input = NULL;
	char **command;
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
 * execute_input - Executes the given command
 * @command: array of strings representing command and its arguments
 * @envp: array of strings containing environment variables
 *
 * Return: status of the command execution
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
