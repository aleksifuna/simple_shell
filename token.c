#include "main.h"
/**
 * token - splits a string into tokens
 * @str: string to split
 * @sep: character separating tokens
 * @end: the string terminating character
 *
 * Return: array of strings.
 */
char **token(char *str, char sep, char end)
{
	int i, n, k;
	int count;
	int m;
	char **av;

	k = 0;
	count = arg_count(str, sep, end) + 2;
	av = malloc(sizeof(char *) * count);
	i = 0;
	count = 0;
	while (1)
	{
		if (str[i] != sep && str[i] != end)
		{
			count++;
		}
		else
		{
			av[k] = malloc(sizeof(char) * (count + 1));
			n = i - count;
			for (m = 0; m < count; m++)
			{
				av[k][m] = str[n];
				n++;
			}
			av[k][m] = '\0';
			k++;
			count = 0;
			if (str[i] == end)
			{
				av[k] = NULL;
				break;
			}
		}
		i++;
	}
	return (av);
}
