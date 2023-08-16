/**
 * str_len - counts the characters in a string upto a specified character
 * @term: terminating character
 * @str: string to count.
 *
 * Return: number of characters in a string.
 */
int str_len(char *str, char term)
{
	int i;

	i = 0;
	while (str[i] != term)
		i++;
	return (i);
}
