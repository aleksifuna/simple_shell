#include "main.h"
/**
 * file_link - returns the file path of a given command
 * @string: the command
 *
 * Return: path of the command
 */
char *file_link(char *string)
{
	int i;
	char **dir_link;
	char *link, *path, *process_name;
	struct stat str;

	path = get_path("PATH=");
	dir_link = token(path, ':', '\0');
	i = 0;
	while (dir_link[i] != NULL)
	{
		link = link_const(dir_link[i], string);
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
	process_name = get_path("_=");
	perror(process_name);
	free(process_name);
	return (NULL);
}
