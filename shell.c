#include "shell.h"

int main(int argc, char **argv, char **envp)
{
	char *name_file = argv[0], *dels = " \n";
	char *get_the_line = NULL, *path;
	int i, status;
	char **command;
	pid_t child_pro;

	while (1)
	{
		get_the_line = print_prompt();
		command = get_commands(get_the_line);
		check_commands(command, envp);
		path = get_path(command);
		
		child_pro = fork();
		if (child_pro == -1)
		{
			perror(name_file);
			exit(EXIT_FAILURE);
		}

		if (child_pro == 0)
		{
			if (execve(path, command, envp) == -1)
			{
				perror(name_file);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return 0;
}
