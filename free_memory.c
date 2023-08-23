#include "main.h"
/**
 * free_memory - frees dynamically allocated memory
 * @str: pointer to character array
 * @arry: pointer to string array
 */
void free_memory(char *str, char **arry)
{
	free(str);
	freestarr(arry);
}
