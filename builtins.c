#include "shell.h"

/**
 * env_builtin - function to print env variables
 * @arr: array
 * Return: index
 *
 */
int env_builtin(char **arr)
{
	int env_index;
	(void)arr;

	for (env_index = 0; __environ[env_index]; env_index++)
	{
		write(STDOUT_FILENO, __environ[env_index], strlen(__environ[env_index]));
		write(STDOUT_FILENO, "\n", strlen("\n"));
	}

	return (env_index);
}

/**
 * exit_builtin - function to exit
 * @arr: array
 * Return: CODE
 *
 */

int exit_builtin(char **arr)
{
	if (arr[1] != NULL)
	{
		exit(atoi(arr[1]));
	}
	else
	{
		return (CODE);
	}
}
