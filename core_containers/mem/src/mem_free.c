#include "../../../inc/core.h"
#include "../../../core_system/inc/system_internal.h"

static t_ssize	deactivate_tracker(t_mem *mem)
{
	t_tracker	*tracker;
	t_size		i;
	t_core	*core;

	core = cr_static();
	i = 0;
	while (i < core->allocs.len)
	{
		tracker = parr_get(&core->allocs, i);
		if (tracker->mem.data == mem->data)
		{
			parr_del(&core->allocs, i);
			parr_free(&tracker->trace);
			free(tracker);
			return (TRUE);
		}
		i++;
	}
	return (false);
}

void	mem_free(t_mem *mem)
{
	t_core	*core;

	core = cr_static();
	if (core->active && core->track_allocs)
		deactivate_tracker(mem);
	free(mem->data);
	mem->data = NULL;
	mem->size = 0;
}
