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
		results = results * 10 + (*string - '0');
		string++;
	}
	return (results);
}
