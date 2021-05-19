#include "../../inc/core.h"

t_str	str_new(t_size len)
{
	t_str	new;

	new.mem = mem_new(len);
	new.len = len;
	return (new);
}
