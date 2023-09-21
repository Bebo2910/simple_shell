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

	file = malloc(_strlen(token) + _strlen(argument) + 2);
	if (!file)
	{
		return (NULL);
	}
	while (token != NULL)
	{
		_strcpy_c(file, token);
		strcat(file, "/");
		strcat(file, argument);

		if (access(file, X_OK) == 0)
		{
			free(fileCopy);
			return (file);
		}
		token = strtok(NULL, dels);
	}
	free(fileCopy);
	free(file);
	return (NULL);
}
/**
 * expo_loc - finds the executable location of a command
 * @argument: the command to search for
 * Return: the full path of the executable, or NULL if not found
 */

char *expo_loc(char *argument)
{
	char *path = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"; 

	if (path)
	{
		path = get_loc(path, argument);
		return (path);
	}

	return (NULL);
}
