#include "main.h"
/**
 * get_path - gets the PATH env variable
 *
 * Return: PATH variable
 */
char *get_path(char *en_var)
{
	int i, j, k, count, en_var_len;
	char **env1 = environ;
	char *link;

	i = j = 0;
	en_var_len = str_len(en_var, '\0');
	while (env1[i] != NULL)
	{
		for (j = 0; j < en_var_len; j++)
		{
			if (env1[i][j] != en_var[j])
			{
				i++;
				break;
			}
		}
		if (j == en_var_len)
		{
			break;
		}
	}
	count = str_len(env1[i] + en_var_len, '\0');
	link = malloc(sizeof(char) * count + 1);
	for (k = 0; k < count; k++)
		link[k] = env1[i][j + k];
	link[k] = '\0';
	return (link);
}
