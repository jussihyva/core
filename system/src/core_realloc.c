#include "../../inc/core.h"
#include "../inc/system_internal.h"

ssize_t	core_realloc(t_mem *mem, size_t new_size)
{
	t_mem	new;

	new = core_malloc(new_size);
	if (new_size < mem->size)
		mem_cpy(new.data, mem->data, new_size);
	else
		mem_cpy(new.data, mem->data, mem->size);
	core_free(mem);
	*mem = new;
	return (new.size);
}
