#include "shell.h"

int check_commands(char **src, char **envp)
{
	int i;

	if (!src)
	{
		return (-1);
	}

	if (_strcmp(src[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(src[0], "env") == 0)
	{
		i = 0;
		while (envp[i] != NULL)
		{
			_puts(envp[i]);
			i++;
		}
	}

	return (0);
}
