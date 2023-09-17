#include "shell.h"

char *print_prompt(void)
{
	char *prompt = ":) ", *get_the_line = NULL;
	size_t num;
	ssize_t numexit;

	if (isatty(0))
	{
		printf("%s", prompt);
	}
	
	numexit = getline(&get_the_line, &num, stdin);

	if (numexit == -1)
	{
		free(get_the_line);
		exit(1);
	}
	if (!get_the_line)
	{
		return (NULL);
	}

	return (get_the_line);
}

char **get_commands(char *line)
{
	int i = 0, word_count = 0, j = 0;
	char *dels = " \n"; 
	char **command;

	if (!line)
	{
		return (NULL);
	}

	while (line[j] != '\0')
	{
		if (line[j] == dels[0])
		{
			word_count++;
		}
		j++;
	}
	command = malloc(sizeof(char *) * (word_count) + 1);
	if (!command)
	{
		return (NULL);
	}
	command[0] = strtok(line, dels);
	while (command[i] != NULL)
	{
		i++;
		command[i] = strtok(NULL, dels);
	}
	command[i] = NULL;

	return (command);
}

char *get_path(char **command)
{
	char *path, *dels = "/\n";

	if (!command)
	{
		return (NULL);
	}

	if (command[0][0] == dels[0])
	{
		path = command[0];
	}
	else
	{
		path = expo_loc(command[0]);
	}

	return (path);
}
