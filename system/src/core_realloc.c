#include "../../inc/core.h"
#include "../inc/system_internal.h"

t_ssize	core_realloc(t_mem *mem, t_size new_size)
{
	t_mem	new;

	new = core_malloc(new_size);
	if (new_size < mem->size)
		mem_move(new.data, mem->data, new_size);
	else
		mem_move(new.data, mem->data, mem->size);
	core_free(mem);
	*mem = new;
	return (new.size);
}
