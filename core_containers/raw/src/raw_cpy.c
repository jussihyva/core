#include "../../../inc/core.h"

t_raw	raw_cpy(t_raw dst, t_raw src, size_t size)
{
	if (src.size < size)

	mcpy(dst.data, src.data, src.size);
	return (dst);
}
