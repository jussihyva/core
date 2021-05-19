#include "../../inc/core.h"

t_size	str_len(t_str src)
{
	t_uint64	len;

	mem_cpy(&len, &src[-sizeof(t_uint64)], sizeof(t_uint64));
	return (len);
}
