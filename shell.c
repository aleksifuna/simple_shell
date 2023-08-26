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
/**
 * handle_biultin - handles the biult-in commands
 * @args: Arguments passed to the shell program
 * @no_of_args: number of arguments passed
 *
 * Return: true if biult in command is detected, else false
 */

bool handle_biultin(char **args, size_t no_of-args)
{
if (_strncmp(args[0], "exit", 4) == 0)
   exit_function(args, no_of_args);

return (false);
}
/**
 * _strncmp - function that compares two strings
 *@str1: string 1
 *@str2: string 2
 *Return: comparison of str1 to str2
 */
int _srncmp(char *str1, char *str2)
{
    int i = 0;

    while (str1[i] != '\0' && str2[i] != '\0')
    {
        if (str1[i] != str2[i])
	{
            return str1[i] - str2[i];
        }
        i++;
    }

    return (str1[i] - str2[i]);
}
