#include "shell.h"

/**
 * execute_command - Executes a command without arguments
 * @command: Command to execute
 * Return: Always 1 to continue shell loop
 */
int execute_command(char *command)
{
	pid_t child_pid;
	int status;
	char *argv[2];

	argv[0] = command;
	argv[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			write(STDERR_FILENO, "./hsh: 1: ", 9);
			write(STDERR_FILENO, command, strlen(command));
			write(STDERR_FILENO, ": not found\n", 12);
			exit(127);
		}
		exit(0);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}

	return (1);
}
