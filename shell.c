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
