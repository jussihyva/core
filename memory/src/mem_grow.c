#include "../../inc/core.h"

t_ssize	mem_grow(t_mem *mem, t_size new_size)
{
	t_mem	new;

	new = mem_new(new_size);
	if (new_size < mem->size)
		mcpy(new.data, mem->data, new_size);
	else
		mcpy(new.data, mem->data, mem->size);
	mem_free(mem);
	*mem = new;
	return (new.size);
}
