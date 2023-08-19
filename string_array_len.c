#include "main.h"
/**
 * array_len - counts the elements in string array
 * @str: string array
 *
 * Return: number of elements in the array
 */
int array_len(char **str)
{
	int i;

	i = 0;
	while (str[i] != NULL)
	{
		i++;
	}
	return (i);
}
