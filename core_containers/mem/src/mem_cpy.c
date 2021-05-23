#include "../../../inc/core.h"

t_mem	mem_cpy(t_mem dst, t_mem src, size_t size)
{
	if (src.size < size)

	mcpy(dst.data, src.data, src.size);
	return (dst);
}
