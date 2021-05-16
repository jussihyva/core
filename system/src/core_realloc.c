#include "../../inc/core.h"

t_mem	core_realloc(t_mem *mem, size_t new_size)
{
	t_mem	new;

	new = core_malloc(new_size);
	if (new_size < mem->size)
		mem_cpy(new.data, mem->data, new_size);
	else
		mem_cpy(new.data, mem->data, mem->size);
	free(mem->data);
	*mem = new;
}
