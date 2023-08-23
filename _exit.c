#include "main.h"
/**
 * shell_exit - exits the shell will with status
 * @str: command from stdin
 */

void shell_exit(char *str)
{
	int i;
	int status;
	char **command;
	char m[] = "exit";

	command = token(str, ' ', '\0');
	for (i = 0; i < 4; i++)
	{
		if (command[0][i] != m[i])
			break;
	}
	if (i == 4)
	{
		if (command[1] == NULL)
			status = 0;
		else
			status = string_int(command[1]);
		free(str);
		freestarr(command);
		exit(status);
	}
	else
	{
		freestarr(command);
	}
}
