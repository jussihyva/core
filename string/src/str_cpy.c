#include "../../inc/core.h"

t_str	str_cpy(t_str dst, t_str src)
{
	if (dst.mem.size < src.len)
		mem_realloc(&dst.mem, src.len);
	mem_cpy(dst.mem, src.mem, src.len);
	dst.len = src.len;
	return (dst);
}
