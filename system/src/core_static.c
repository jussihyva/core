#include "../../inc/core.h"
#include "../inc/system_internal.h"
#include "../inc/system.h"

t_core	*core_static()
{
	static t_core	core;

	return (&core);
}
