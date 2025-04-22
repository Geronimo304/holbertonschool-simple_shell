#include "shell.h"
#include <sys/stat.h>

/**
 * get_path - Get the PATH environment variable
 * Return: The PATH string or NULL if not found
 */
char *get_path(void)
{
	int i;
	char *path = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
	}
	return (path);
}

/**
 * find_command - Find a command in PATH
 * @command: Command to find
 * Return: Full path to command or NULL if not found
 */
char *find_command(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_len, directory_len;
	struct stat buffer;

	if (command == NULL)
		return (NULL);

	if (strchr(command, '/') != NULL)
	{
		if (stat(command, &buffer) == 0)
			return (strdup(command));
		return (NULL);
	}

	path = get_path();
	if (path == NULL)
		return (NULL);

	path_copy = strdup(path);
	if (path_copy == NULL)
		return (NULL);

	command_len = strlen(command);
	path_token = strtok(path_copy, ":");
	while (path_token != NULL)
	{
		directory_len = strlen(path_token);
		file_path = malloc(directory_len + command_len + 2);
		if (file_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		strcpy(file_path, path_token);
		strcat(file_path, "/");
		strcat(file_path, command);

		if (stat(file_path, &buffer) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		free(file_path);
		path_token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
