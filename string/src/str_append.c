#include "../../inc/core.h"

t_str	str_append(t_str dst, t_str src)
{
	t_pmem	mem_ptr;

	if (dst.mem.size < dst.len + src.len)
		mem_grow(&dst.mem, (dst.len + src.len) * 3);
	mem_ptr = pmem(dst.mem, dst.len, src.len + dst.len);
	mem_cpy(mem_ptr,  src.mem, src.len);
	dst.len = dst.len + src.len;
	return (dst);
}
