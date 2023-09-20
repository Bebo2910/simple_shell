#include "shell.h"
/**
 * get_loc - finds the location of an executable
 * @path: the value of the PATH environment variable
 * @argument: the name of the executable file
 * Return: a pointer to the full path of the file,
 * or NULL if not found or error
 */

char *get_loc(char *path, char *argument)
{
	char *token, *file, *fileCopy = strdup(path);
	char *dels = ":";

	token = strtok(fileCopy, dels);

	while (token != NULL)
	{
		file = malloc(strlen(token) + strlen(argument) + 2);
		_strcpy_c(file, token);
		strcat(file, "/");
		strcat(file, argument);

		if (access(file, X_OK) == 0)
		{
			return (file);
		}

		free(file);
		token = strtok(NULL, dels);
	}

	return (NULL);
}
/**
 * expo_loc - finds the executable location of a command
 * @argument: the command to search for
 * Return: the full path of the executable, or NULL if not found
 */

char *expo_loc(char *argument)
{
	char *path;

	path = getenv("PATH");

	if (path)
	{
		path = get_loc(path, argument);
		return (path);
	}

	return (NULL);
}
