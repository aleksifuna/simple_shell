#include "main.h"
/**
 * return_comments - function that replaces first instance of '#' with '\0'
 *
 *@buf: address of the string to modify
 *
 *Return: always 0
 */
void return_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
	{
		if (buf[i] == '#' && (!i || buf[i-1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
	}
}
