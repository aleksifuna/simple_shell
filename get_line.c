#include "main.h"
/**
 * get_line - gets a string of characters fom the standard input
 *
 * Return: string from stdin
 */
char *get_line(void)
{
	ssize_t byteRead;
	char buffer[BUFFER_SIZE];
	char *line;
	int i;

	byteRead = read(STDIN_FILENO, buffer, sizeof(buffer));
	if (byteRead < 1)
	{
		write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (byteRead == -1)
	{
		perror("Error");
	}
	if (buffer[0] == '\n')
		return (NULL);
	line = malloc(sizeof(char) * byteRead);
	for (i = 0; i < byteRead - 1; i++)
		line[i] = buffer[i];
	line[i] = '\0';
	return (line);
}
