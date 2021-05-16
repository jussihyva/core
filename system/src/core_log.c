#include "../../inc/core.h"
#include "../inc/system.h"

ssize_t	print_tracker(void *data, size_t i)
{
	t_tracker *tracker;

	tracker = data;
	if (tracker->mem.data)
	{
		printf("memptr: \033[1;31m%p\033[0m\n", tracker->mem.data);
		printf("memsize: \033[1;31m%lu\033[0m\n", tracker->mem.size);
	}
	if (tracker->trace)
		printf("%s\n", tracker->trace);
	return (i);
}

ssize_t	print_error(void *data, size_t i)
{
	t_error *error;

	error = data;
	if (error->message)
		printf("%s\n", error->message);
	if (error->trace)
		printf("%s\n", error->trace);
	return (i);
}

void	core_log()
{
	if (g_core.track_errors == true)
		parr_iter(&g_core.errors, print_error);
	if (g_core.track_allocs == true)
		parr_iter(&g_core.allocs, print_tracker);
}
