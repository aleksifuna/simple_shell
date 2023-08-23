#include "main.h"
/**
 * main - simple shell
 *
 * Return: 0 on success.
 */
int main(void)
{
	char *lineptr;
	int status;
	pid_t child_pid;
	char **arg;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		lineptr = get_line();
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
			free(lineptr);
			freestarr(arg);
			return (98);
		}
		if (child_pid == 0)
		{
			execve(arg[0], arg, environ);
			perror("./hsh");
			return (98);
		}
		else
		{
			wait(&status);
		}
		free(lineptr);
		freestarr(arg);
	}
	return (0);
}
