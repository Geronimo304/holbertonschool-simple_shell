#include "shell.h"

/**
 * build_path - Combina directorio y comando en una ruta completa
 * @dir: El directorio
 * @cmd: El comando
 * Return: Puntero a nueva ruta, o NULL si falla
 */
char *build_path(char *dir, char *cmd)
{
	int len = strlen(dir) + strlen(cmd) + 2;
	char *full = malloc(len);

	if (!full)
		return (NULL);
	strcpy(full, dir);
	strcat(full, "/");
	strcat(full, cmd);
	return (full);
}

/**
 * find_command - Encuentra un comando en el PATH
 * @command: Comando a buscar
 * Return: Ruta completa o NULL si no se encuentra
 */
char *find_command(char *command)
{
	char *path, *path_copy, *token, *full;
	struct stat st;

	if (!command)
		return (NULL);

	if (strchr(command, '/') && stat(command, &st) == 0)
		return (strdup(command));

	path = get_path();
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		full = build_path(token, command);
		if (!full)
		{
			free(path_copy);
			return (NULL);
		}

		if (stat(full, &st) == 0)
		{
			free(path_copy);
			return (full);
		}

		free(full);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

