#include "main.h"
/**
 * handle_error - inserts program name before error
 */
void handle_error(void)
{
	char *process_name;

	process_name = get_path("_=");
	perror(process_name);
	free(process_name);
}
