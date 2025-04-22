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
