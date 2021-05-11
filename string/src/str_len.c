#include "../../inc/core.h"

size_t	str_len(t_str src)
{
	uint64_t	len;

	mem_cpy(&len, &src[-sizeof(uint64_t)], sizeof(uint64_t));
	return (len);
}
