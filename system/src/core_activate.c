#include "../../inc/core.h"
#include "../inc/system.h"
#include "../inc/system_internal.h"

void	core_activate()
{
	t_core	*core;

	core = core_static();
	core->active = true;
	core->track_errors = CR_TRACK_ERROR;
	core->track_errors_backtrace = CR_TRACK_ERROR_BACKTRACE;
	core->track_allocs = CR_TRACK_ALLOC;
	core->track_allocs_backtrace = CR_TRACK_ALLOC_BACKTRACE;
	if (core->track_errors == true)
		core->errors = parr_new(1);
	if (core->track_allocs == true)
		core->allocs = parr_new(1);
	printf("\n\033[32;1mCORE SYSTEM\033[0m\n\n");
	print("You have activated the core system for memory management and debugging.\n\n");
}
