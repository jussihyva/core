#include "../../../inc/core.h"

t_str	str_new(t_size len)
{
	t_str	new;

	new.mem = mem_new(len + 1);
	new.len = len;
	new.mem.data[0] = '\0';
	return (new);
}
