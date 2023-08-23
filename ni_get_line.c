#include "main.h"
/**
 * ni_get_line - reads commands from a file one line after the other
 * @input: pointer to character array
 * @idx: pointer to index
 *
 * Return: string of characters
 */
char *ni_get_line(char **input, int *idx)
{
	int i, command_length;
	char *line;
	char **commands;

	if (*idx == 0)
		*input = get_line();
	commands = token(*input, '\n', '\0');
	if (commands[*idx] == NULL)
	{
		free(*input);
		freestarr(commands);
		exit(0);
	}
	else
	{
		command_length = str_len(commands[*idx], '\0') + 1;
		line = malloc(sizeof(char) * command_length);
		for (i = 0; i < command_length - 1; i++)
			line[i] = commands[*idx][i];
		line[i] = '\0';
		*idx += 1;
		freestarr(commands);
		return (line);
	}
}
