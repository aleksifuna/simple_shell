#include "main.h"
/**
 * main - terminates calling process
 *
 *
 *
 */
void exit_function(void)
{
	size_t lineptr;
	char *len = NULL;
	char *exitcommand = "exit";
	int i;


	i = 0;


		write(STDOUT_FILENO, "$ ", 2);

		getline(&len, &lineptr, stdin);

while (len[i]!= 0 && exitcommand[i] != 0)
{

		if(len[i] != exitcommand[i])
		{
			break;
		}

		i++;
		free(len);

}
exit(0);
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
}
