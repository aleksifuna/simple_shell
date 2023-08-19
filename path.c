#include "main.h"
/**
 * get_path - gets the PATH env variable
 *
 * Return: PATH variable
 */
char *get_path(void)
{
	int i, j, k, count;
	char **env1 = environ;
	char pth[] = "PATH=";
	char *link;

	i = j = 0;
	while (env1[i] != NULL)
	{
		for (j = 0; j < 5; j++)
		{
			if (env1[i][j] != pth[j])
			{
				i++;
				break;
			}
		}
		if (j == 5)
		{
			break;
		}
	}
	count = str_len(env1[i] + 5, '\0');
	link = malloc(sizeof(char) * count);
	j = 5;
	for (k = 0; k < count - 1; k++)
		link[k] = env1[i][j + k];
	link[k] = '\0';
	return (link);
}
