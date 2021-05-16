#include "inc/core.h"

enum	e_system
{
	ACTIVATE,
	RECOVERY_POLICY,
	ERROR_TRACE,
	ALLOC_TRACE,
};

t_core	*core_static()
{
	static t_core	core;

	return (&core);
}

void	core_set(size_t flag)
{
	t_core	*core;

	core = core_static();
	if (flag == ACTIVATE)
		core->active = true;
}

bool	core_check(size_t flag)
{
	t_core	*core;

	core = core_static();
	if (core->active = true)
		return (core->active);
}

int	main(void)
{
	core_set(ACTIVATE);
	if (core_check(ACTIVATE))
		print("TRUE\n");
}