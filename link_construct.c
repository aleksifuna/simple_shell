#include "main.h"
/**
 * link_const - constructs a path link to a program
 * @dlink: PATH directory links.
 * @command: command input from stdin
 *
 * Return: pathlink to a program.
 */
char *link_const(char *dlink, char *command)
{
	int i, j;
	char *path_link;
	int comlen, pathlen, linklen;

	comlen = str_len(command, '\0');
	pathlen = str_len(dlink, '\0');
	linklen = comlen + pathlen + 2;
	path_link = malloc(sizeof(char) * linklen);
	j = 0;
	for (i = 0; i < linklen - 1; i++)
	{
		if (i < pathlen)
		{
			path_link[i] = dlink[i];
		}
		else if (i == pathlen)
		{
			path_link[i] = '/';
		}
		else
		{
			path_link[i] = command[j];
			j++;
		}
	}
	path_link[i] = '\0';
	return (path_link);
}
