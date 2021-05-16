#include "../inc/system.h"
#include "../inc/system_internal.h"

void	create_tracker(t_mem mem)
{
	t_tracker	*tracker;
	t_core		*core;

	core = core_static();
	tracker = malloc(sizeof(t_tracker));
	if (core->track_allocs_backtrace == true)
		tracker->trace = core_stacktrace(2);
	else
		tracker->trace = CR_PARR_NULL;
	tracker->mem = mem;
	parr_add_last(&core->allocs, tracker);
}

ssize_t	core_malloc_setup(t_mem mem)
{
	t_core	*core;

	core = core_static();
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
	if (core->track_allocs == 1)
		create_tracker(mem);
	return (1);
}

t_mem	core_malloc(size_t bytes)
{
	t_mem	out;
	t_core	*core;

	core = core_static();
	out.data = malloc(bytes);
	out.size = bytes;
	if (core->active == true)
		if (!(core_malloc_setup(out)))
			return (CR_MEM_NULL);
	return (out);
}
