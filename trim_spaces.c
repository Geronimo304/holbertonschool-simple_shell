#include "shell.h"

/**
 * trim_spaces - Elimina espacios en blanco al principio y al final de una cadena
 * @str: Cadena original (modificada en el lugar)
 * Return: Puntero a la cadena sin espacios
 */
char *trim_spaces(char *str)
{
	char *start, *end;

	if (str == NULL)
		return (NULL);

	start = str;

	while (*start == ' ' || *start == '\t')
		start++;

	if (*start == '\0')
		return (strdup(""));

	end = start + strlen(start) - 1;

	while (end > start && (*end == ' ' || *end == '\t'))
		end--;

	*(end + 1) = '\0';

	return (strdup(start));
}
