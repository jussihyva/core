#include "../../inc/core.h"

t_pstr	pstr(t_str src, size_t s, size_t t)
{
	t_mem	mem;

	mem = mem_assign(src.mem.data, src.mem.size);
	return (pmem(mem, s, t));
}
