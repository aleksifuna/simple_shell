#include "main.h"
/**
 * free_string_memory - frees dynamically allocated memory
 * @str: pointer to string array
 * @arry: pointer to string array
 */
void free_string_memory(char **str, char **arry)
{
	free(str);
	freestarr(arry);
}
