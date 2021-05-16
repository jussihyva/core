#include "../../inc/core.h"
#include "../inc/system.h"

void	cr_free_trackers()
{
	size_t	i;
	t_tracker	*t;

	i = 0;
	while (i < g_core.allocs.len)
	{
		t = parr_get(&g_core.allocs, i);
		free(t->trace);
		i++;
	}
}

void	cr_free_errors()
{
	size_t	i;
	t_error	*t;

	i = 0;
	while (i < g_core.errors.len)
	{
		t = parr_get(&g_core.errors, i);
		free(t->trace);
		free(t->message);
		i++;
	}
}

void	core_deactivate()
{
	if (g_core.track_errors == true)
	{
		cr_free_errors();
		parr_free(&g_core.errors);
	}
	if (g_core.track_allocs == true)
	{
		cr_free_trackers();
		parr_free(&g_core.allocs);
	}
}
