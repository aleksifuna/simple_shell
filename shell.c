#include "main.h"
/**
 * main - simple shell
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *lineptr, *input;
	int status, index;
	pid_t child_pid;
	char **arg;

	index = 0;
	while (1)
	{
		if (isatty(0) == 1)
		{
			write(STDOUT_FILENO, "$ ", 2);
			lineptr = get_line();
		}
		else
			lineptr = ni_get_line(&input, &index);
		if (lineptr == NULL)
			continue;
		shell_exit(lineptr);
		arg = _which(lineptr);
		if (arg == NULL)
		{
			free(lineptr);
			continue;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("./hsh");
			free_memory(lineptr, arg);
			return (-1);
		}
		if (child_pid == 0)
		{
			execve(arg[0], arg, environ);
		}
		else
			wait(&status);
		free_memory(lineptr, arg);
	}
	return (0);
}
