#include "main.h"
/**
 * main - simple shell
 *
 * Return: 0 on success
 */
int main(void)
{
	char *lineptr;
	int status;
	size_t len;
	pid_t child_pid;
	char *argv[2];

	lineptr = NULL;
	len = 0;
	write(STDOUT_FILENO, "$", 1);
	while (1)
	{
		if (getline(&lineptr, &len, stdin) == -1)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		lineptr[str_len(lineptr, '\n')] = '\0';
		argv[0] = lineptr;
		argv[1] = NULL;
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
			return (98);
		}
		if (child_pid == 0)
		{
			execve(argv[0], argv, NULL);
			perror("Error:");
			return (98);
		}
		else
		{
			wait(&status);
			write(STDOUT_FILENO, "$", 1);
		}
	}
	free(lineptr);
	return (0);
}
