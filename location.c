#include "shell.h"

char *get_loc(char *path, char *argument)
{
	char *token, *file, *fileCopy = strdup(path);
	char *dels = ":", *buffer;

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
