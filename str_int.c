#include "main.h"
/**
 * string_int - converts a string into equivalent integer
 * @string: string to be converted to integer
 *
 * Return: integer from the string.
 */
int string_int(char *string)
{
	int results = 0;

	while (*string)
	{
		if (*string >= '0' && *string <= '9')
		{
			results = results * 10 + (*string - '0');
			string++;
		}
		else
		{
			perror(string);
			return (1);
		}
	}
	return (results);
}
