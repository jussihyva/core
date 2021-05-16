#include "../../inc/core.h"
#include "../inc/system.h"
#include "../inc/system_internal.h"

void	cr_free_trackers()
{
	size_t	i;
	t_tracker	*t;
	t_core	*core;
	core = core_static();

	i = 0;
	while (i < core->allocs.len)
	{
		t = parr_get(&core->allocs, i);
		parr_free(&t->trace);
		free(t);
		i++;
	}
}

void	cr_free_errors()
{
	size_t	i;
	t_error	*t;
	t_core	*core;

	core = core_static();
	i = 0;
	while (i < core->errors.len)
	{
		t = parr_get(&core->errors, i);
		parr_free(&t->trace);
		free(t->message);
		free(t);
		i++;
	}
}

void	core_deactivate()
{
	t_core	*core;

	core = core_static();
	if (core->track_errors == true)
	{
		cr_free_errors();
		parr_free(&core->errors);
	}
	if (core->track_allocs == true)
	{
		cr_free_trackers();
		parr_free(&core->allocs);
	}
}
