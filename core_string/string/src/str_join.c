#include "../../../inc/core.h"

t_str	str_join(t_str dst, t_str src)
{
	t_hmem	mem_ptr;

	if (dst.mem.size < dst.len + src.len)
		mem_realloc(&dst.mem, (dst.len + src.len) * 3);
	mem_ptr = hmem_range(dst.mem, dst.len, src.len + dst.len);
	mem_cpy(mem_ptr,  src.mem, src.len);
	dst.len = dst.len + src.len;
	dst.mem.data[dst.len] = '\0';
	return (dst);
}
