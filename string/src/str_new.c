#include "../../inc/core.h"

t_str	str_new(t_size len)
{
	t_str		new;
	t_uint64	_len;

	new = (char *)malloc(sizeof(char) * len + sizeof(t_uint64) + 1);
	if (!new)
	{
		print("Allocation failed in function: arr_new!\n");
		exit(-1);
	}
	mem_set(new, 0, sizeof(t_uint64));
	_len = len;
	mem_cpy(new, &_len, sizeof(t_uint64));
	new[len + sizeof(t_uint64)] = '\0';
	return (&new[sizeof(t_uint64)]);
}
