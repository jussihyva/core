#include "../../../inc/core.h"

t_raw	raw_assign(void *src, size_t size)
{
	t_raw	raw;

	raw.data = src;
	raw.size = size;
	return (raw);
}
