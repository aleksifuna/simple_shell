#include "main.h"
/**
 * _which - creates an array of strings for execve
 * @arg_str: input string from stdin
 *
 * Return: string array to use in execve function
 */
char **_which(char *arg_str)
{
	int i, k, len, count;
	struct stat st;
	char **arg, **av;

	arg = token(arg_str, ' ', '\0');
	i = k = 0;
	count = array_len(arg);
	av = malloc(sizeof(char *) * (count + 1));
	if (arg[0][0] == '/')
	{
		if (stat(arg[0], &st) != 0)
		{
			handle_error();
			free_string_memory(av, arg);
			return (NULL);
		}
	}
	else
	{
		arg[0] = file_link(arg[0]);
		if (arg[0] == NULL)
		{
			free_string_memory(av, arg);
			return (NULL);
		}
	}
	while (arg[k] != NULL)
	{
		len = str_len(arg[k], '\0');
		av[k] = malloc(sizeof(char) * (len + 1));
		for (i = 0; i < len; i++)
			av[k][i] = arg[k][i];
		av[k][i] = '\0';
		k++;
	}
	av[k] = NULL;
	freestarr(arg);
	return (av);
}
