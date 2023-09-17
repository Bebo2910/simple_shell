/**
 * check_commands - checks if the input is a built-in command
 * @src: pointer to an array of strings
 * @envp: pointer to the environment variables
 * Description: this function compares the first string in src with
 * "exit" and "env", and executes the corresponding actions if they match.
 * Return: 0 if successful or -1 if src is NULL
 */
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
