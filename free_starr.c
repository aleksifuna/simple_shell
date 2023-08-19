#include "main.h"
/**
 * freestarr - frees an array of strings.
 * @str: array of strings to free
 */
void freestarr(char **str)
{
	int i;

	if (str == NULL)
	{
		return;
	}
	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
}
