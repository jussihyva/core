#include "../../inc/core.h"
#include "../inc/system.h"

ssize_t	print_line(void *data, size_t i)
{
	char	*str;

	str = data;
	print("%s\n", str);
	return (i);
}

ssize_t	print_tracker(void *data, size_t i)
{
	t_tracker *tracker;

	tracker = data;
	if (tracker->mem.data)
	{
		printf("memptr: \033[1;31m%p\033[0m\n", tracker->mem.data);
		printf("memsize: \033[1;31m%lu\033[0m\n", tracker->mem.size);
	}
	if (!(parr_null(&tracker->trace)))
		parr_iter(&tracker->trace, print_line);
	return (i);
}

ssize_t	print_error(void *data, size_t i)
{
	t_error *error;

	error = data;
	if (error->message)
		printf("%s\n", error->message);
	if (!(parr_null(&error->trace)))
		parr_iter(&error->trace, print_line);
	return (i);
}

void	core_log()
{
	if (g_core.track_errors == true)
		parr_iter(&g_core.errors, print_error);
	if (g_core.track_allocs == true)
		parr_iter(&g_core.allocs, print_tracker);
}
