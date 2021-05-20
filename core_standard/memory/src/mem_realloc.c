#include "../../../inc/core.h"

t_ssize	mem_realloc(t_mem *m, t_size new_size)
{
	t_mem	new;

	new = mem(new_size);
	if (new_size < m->size)
		mcpy(new.data, m->data, new_size);
	else
		mcpy(new.data, m->data, m->size);
	mem_free(m);
	*m = new;
	return (new.size);
}
