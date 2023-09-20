#include "shell.h"
/**
 * main - a simple shell program
 * @argc: the number of arguments
 * @argv: the array of arguments
 * @envp: the array of environment variables
 * Description:the function reads line from standard input
 * split it into words,check if valid , find path of command
 * and executes it in child process and repeat it until user types exit
 * Return: 0 on success, or exit status of the child process if fails
 */

int main(int argc, char **argv, char **envp)
{
	char *get_the_line = NULL, *path;
	char **command;
	pid_t child_pro;

	(void)argc;
	while (1)
	{
		get_the_line = print_prompt();
		command = get_commands(get_the_line);
		check_commands(command, envp);
		path = get_path(command);
		child_pro = fork();
		if (child_pro == -1)
		{
			free(get_the_line);
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
		if (child_pro == 0)
		{
			if (execve(path, command, envp) == -1)
			{
				_puts(argv[0]);
				_puts(":");
				_puts(" No such file or directory");
				_putchar('\n');
				free(path), free(command);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		free(path), free(command), free(get_the_line);
	}
	return (0);
}
