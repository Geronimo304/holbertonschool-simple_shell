#include "shell.h"

/**
 * main - Simple shell entry point
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	int status = 1;
	int interactive;

	interactive = isatty(STDIN_FILENO);

	while (status)
	{
		if (interactive)
			write(STDOUT_FILENO, "#cisfun$ ", 9);

		line = read_line();

		if (line == NULL)
		{
			if (interactive)
				write(STDOUT_FILENO, "\n", 1);
			break;
		}

		line = trim_spaces(line);

		if (line[0] == '\0')
		{
			free(line);
			continue;
		}

		if (is_exit(line))
		{
			free(line);
			exit(0);
		}

		status = execute_command(line);
		free(line);
	}
	return (0);
}

/**
 * is_exit - Checks if command is "exit"
 * @command: command to check
 * Return: 1 if exit, 0 otherwise
 */
int is_exit(char *command)
{
	return (strcmp(command, "exit") == 0);
}
