#include "main.h"
/**
 * arg_count - number of elements in an argument
 * @arg_string: string with arguments
 * @end: terminating character;
 * @sep: arguments separator
 *
 * Return: number of arguments
 */
int arg_count(char *arg_string, char sep, char end)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (arg_string[i] != end)
	{
		if (arg_string[i] == sep)
		{
			count++;
		}
		i++;
	}
	return (count);
}
