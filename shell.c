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
	size_t len;
	pid_t child_pid;
	char **arg;

	while (1)
	{
		lineptr = NULL;
		len = 0;
		write(STDOUT_FILENO, "$ ", 2);
		if (getline(&lineptr, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(lineptr);
			break;
		}
		lineptr[str_len(lineptr, '\n')] = '\0';
		if (lineptr[0] == '\0')
		{
			free(lineptr);
			continue;
		}
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
