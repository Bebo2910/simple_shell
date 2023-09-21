#include "shell.h"
/**
 * print_prompt - prints a prompt and reads a line
 * from standard input
 * Return: a pointer to the line read,
 * or NULL on error
 */
char *print_prompt(void)
{
	char *get_the_line = NULL;
	size_t num;

	if (isatty(STDIN_FILENO))
	{
		_puts(":) ");
	}
	getline(&get_the_line, &num, stdin);
	if (!get_the_line)
	{
		return (NULL);
	}

	return (get_the_line);
}
/**
 * get_commands - splits a line into words
 * separated by delimiters
 * @line: a pointer to the line to split
 * Return: a pointer to an array of words
 * or NULL on error
 */
char **get_commands(char *line)
{
	int i = 0;
	char *dels = " \n";
	char **command;

	if (!line)
	{
		return (NULL);
	}

	command = malloc(sizeof(char *) * 11);
	command[0] = strtok(line, dels);
	if (command[0] == NULL)
	{
		free(command);
		return (NULL);
	}
	while (command[i] != NULL)
	{
		i++;
		command[i] = strtok(NULL, dels);
	}
	command[i] = NULL;
	return (command);
}
/**
 * *get_path - returns the path of a command
 * @command: a pointer to an array of words
 * that represent the command
 * Return: a pointer to the path of the command
 * or NULL on error
 */
char *get_path(char **command)
{
	char *path, *dels = "/\n";

	if (!command)
	{
		return (NULL);
	}

	if(command[0][0] == dels[0])
	{
		path = command[0];
		return (path);
	}
	else
	{
		path = expo_loc(command[0]);
		return (path);
	}

	return (NULL);
}
