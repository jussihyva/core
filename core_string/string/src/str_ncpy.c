#include "../../../inc/core.h"

t_str	str_ncpy(t_str dst, t_str src, size_t len)
{
	if (dst.mem.size < len)
		mem_realloc(&dst.mem, src.len);
	if (src.len < len)
		len = src.len;
	mem_cpy(dst.mem, src.mem, len);
	dst.len = len;
	dst.mem.data[len] = '\0';
	return (dst);
}
