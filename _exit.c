#include "main.h"
/**
<<<<<<< HEAD
 *exit_function  - handles the "exit"
 *
 *
 *Return: nothing
 */
void exit_function(char **exit_args, size_t no_of-args)
{
	int status = EXIT_SUCCESS;

	if (exit_args[1])
		status = _atoi(exit_args[1]);

	free_vector(exit_args, no_of_args[1]);
	exit(status);
}

/**
 * _atoi - converts a string to an integer
 *
 * @s: the string to be converted
 * Return: 0 if no number in string
 */
int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;

	return(output);
=======
 * shell_exit - exits the shell will with status
 * @str: command from stdin
 */

void shell_exit(char *str)
{
	int i;
	int status;
	char **command;
	char m[] = "exit";

	command = token(str, ' ', '\0');
	for (i = 0; i < 4; i++)
	{
		if (command[0][i] != m[i])
			break;
	}
	if (i == 4)
	{
		if (command[1] == NULL)
			status = 0;
		else
			status = string_int(command[1]);
		free(str);
		freestarr(command);
		exit(status);
	}
	else
	{
		freestarr(command);
	}
>>>>>>> a59dfc36e243633641387c2726e48979a3948cb0
}
