#include "../../../inc/core.h"

t_hstr	hstr_range(t_str src, size_t s, size_t t)
{
	t_mem	mem;

	mem = mem_assign(src.mem.data, src.mem.size);
	return (hmem_range(mem, s, t));
}
