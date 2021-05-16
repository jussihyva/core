#include "../inc/system.h"

void	create_tracker(t_mem mem)
{
	t_tracker	*tracker;

	tracker = malloc(sizeof(t_tracker));
	if (g_core.track_allocs_backtrace == true)
		tracker->trace = core_stacktrace(1);
	else
		tracker->trace = NULL;
	tracker->mem = mem;
	parr_add_last(&g_core.allocs, tracker);
}

ssize_t	core_malloc_setup(t_mem mem)
{
	if (!mem.data && CR_RECOVERY_POLICY == 0)
	{
		core_error(CR_FILE_POS, "FAILED ALLOCATION");
		core_log();
		exit(-1);
	}
	else if (!mem.data && CR_RECOVERY_POLICY == 1)
	{
		core_error(CR_FILE_POS, "FAILED ALLOCATION");
		return (0);
	}
	if (g_core.track_allocs == 1)
		create_tracker(mem);
	return (1);
}

t_mem	core_malloc(size_t bytes)
{
	t_mem	out;

	out.data = malloc(bytes);
	out.size = bytes;
	g_core.alloc_index++;
	if (g_core.active == true)
		if (!(core_malloc_setup(out)))
			return (CR_MEM_NULL);
	return (out);
}
