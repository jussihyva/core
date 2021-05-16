#include "../../inc/core.h"
#include "../inc/system.h"

static ssize_t	deactivate_tracker(t_mem *mem)
{
	t_tracker	*tracker;
	size_t		i;

	i = 0;
	while (i < g_core.allocs.len)
	{
		tracker = parr_get(&g_core.allocs, i);
		if (tracker->mem.data == mem->data)
		{
			parr_del(&g_core.allocs, i);
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
	if (g_core.active && g_core.track_allocs)
		deactivate_tracker(mem);
	free(mem->data);
	mem->data = NULL;
	mem->size = 0;
}
