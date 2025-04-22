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
	char *cmd_path;
	char error_msg[1024];
	char *program_name = "./hsh";

	cmd_path = find_command(command);
	if (cmd_path == NULL)
	{
		sprintf(error_msg, "%s: 1: %s: not found\n", program_name, command);
		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (1);
	}
	argv[0] = cmd_path;
	argv[1] = NULL;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		free(cmd_path);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(cmd_path, argv, environ) == -1)
		{
			sprintf(error_msg, "%s: 1: %s: not found\n", program_name, command);
			write(STDERR_FILENO, error_msg, strlen(error_msg));
			free(cmd_path);
			exit(127);
		}
		exit(0);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(cmd_path);
	}
	return (1);
}
