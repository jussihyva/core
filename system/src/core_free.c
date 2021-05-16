#include "../../inc/core.h"
#include "../inc/system_internal.h"

static ssize_t	deactivate_tracker(t_mem *mem)
{
	t_tracker	*tracker;
	size_t		i;
	t_core	*core;

	core = core_static();
	i = 0;
	while (i < core->allocs.len)
	{
		tracker = parr_get(&core->allocs, i);
		if (tracker->mem.data == mem->data)
		{
			parr_del(&core->allocs, i);
			parr_free(&tracker->trace);
			free(tracker);
			return (true);
		}
		i++;
	}
	return (false);
}

void	core_free(t_mem *mem)
{
	t_core	*core;

	core = core_static();
	if (core->active && core->track_allocs)
		deactivate_tracker(mem);
	free(mem->data);
	mem->data = NULL;
	mem->size = 0;
}
