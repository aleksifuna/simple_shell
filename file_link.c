#include "main.h"
/**
 * file_link - returns the file path of a given command
 * @string: the command
 *
 * Return: path of the command
 */
char *file_link(char *string)
{
	int comlen, pathlen, linklen, i, n, m;
	char **dir_link;
	char *link, *path;
	struct stat str;

	comlen = str_len(string, '\0');
	path = get_path();
	dir_link = token(path, ':', '\0');
	i = 0;
	while (dir_link[i] != NULL)
	{
		n = 0;
		pathlen = str_len(dir_link[i], '\0');
		linklen = comlen + pathlen + 2;
		link = malloc(sizeof(char) * linklen);
		for (m = 0; m < linklen - 1; m++)
		{
			if (m < pathlen)
			{
				link[m] = dir_link[i][m];
			}
			else if (m == pathlen)
			{
				link[m] = '/';
			}
			else
			{
				link[m] = string[n];
				n++;
			}
		}
		link[m] = '\0';
		if (stat(link, &str) == 0)
		{
			free(string);
			free(path);
			freestarr(dir_link);
			return (link);
		}
		free(link);
		i++;
	}
	free(path);
	freestarr(dir_link);
	free(string);
	perror(string);
	return (NULL);
}
