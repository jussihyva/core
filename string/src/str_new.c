#include "../../inc/core.h"

t_str	str_new(size_t len)
{
	t_str	new;

	new = (char *)malloc(sizeof(char) * len + sizeof(uint64_t) + 1);
	if (!new)
	{
		printf("Allocation failed in function: arr_new!\n");
		exit(-1);
	}
	mem_set(new, 0, sizeof(uint64_t));
	uint64_t _len = len;
	mem_cpy(new, &_len, sizeof(uint64_t));
	new[len + sizeof(uint64_t)] = '\0';
	return (&new[sizeof(uint64_t)]);
}
