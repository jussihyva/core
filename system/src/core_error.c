#include "../../inc/core.h"
#include "../inc/system.h"

void	core_error(t_file_pos *err_pos, char *message)
{
	t_error	*error;

	error = malloc(sizeof(t_error));
	error->message = format(
			"ERROR \033[1;31m%s\033[0m, \033[1;31m%s\033[0m, \033[1;31m%d\033[0m\n%s",
			err_pos->file,
			err_pos->func,
			err_pos->line,
			message);
	error->trace = core_stacktrace(1);
	parr_add_last(&g_core.errors, error);
}