#include "../../../inc/core.h"

t_mem	mem_assign(void *src, size_t size)
{
	t_mem	mem;

	mem.data = src;
	mem.size = size;
	return (mem);
}
