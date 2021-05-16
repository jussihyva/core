#include "../../inc/core.h"
#include "../inc/system.h"

void	core_activate()
{
	g_core.active = true;
	g_core.track_errors = CR_TRACK_ERROR;
	g_core.track_errors_backtrace = CR_TRACK_ERROR_BACKTRACE;
	g_core.track_allocs = CR_TRACK_ALLOC;
	g_core.track_allocs_backtrace = CR_TRACK_ALLOC_BACKTRACE;
	if (g_core.track_errors == true)
		g_core.errors = parr_new(1);
	if (g_core.track_allocs == true)
		g_core.allocs = parr_new(1);
	printf("\n\033[32;1mCORE SYSTEM\033[0m\n\n");
	print("You have activated the core system for memory management and debugging.\n\n");
}
