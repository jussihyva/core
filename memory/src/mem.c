#include "../../inc/core.h"
#include "../../system/inc/system_internal.h"

void	create_tracker(t_mem mem)
{
	t_tracker	*tracker;
	t_core		*core;

	core = cr_static();
	tracker = malloc(sizeof(t_tracker));
	if (core->track_allocs_backtrace == true)
		tracker->trace = cr_stacktrace(2);
	else
		tracker->trace = CR_PARR_NULL;
	tracker->mem = mem;
	parr_add_last(&core->allocs, tracker);
}

t_ssize	mem_setup(t_mem mem)
{
	t_core	*core;

	core = cr_static();
	if (!mem.data && CR_RECOVERY_POLICY == 0)
	{
		cr_error(CR_FILE_POS, "FAILED ALLOCATION");
		cr_log();
		exit(-1);
	}
	else if (!mem.data && CR_RECOVERY_POLICY == 1)
	{
		cr_error(CR_FILE_POS, "FAILED ALLOCATION");
		return (0);
	}
	if (core->track_allocs == 1)
		create_tracker(mem);
	return (1);
}

t_mem	mem(t_size bytes)
{
	t_mem	out;
	t_core	*core;

	core = cr_static();
	out.data = malloc(bytes);
	out.size = bytes;
	if (core->active == true)
		if (!(mem_setup(out)))
			return (CR_MEM_NULL);
	return (out);
}
