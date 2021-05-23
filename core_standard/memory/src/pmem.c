#include "../../../inc/core.h"

t_hmem	pmem(t_mem src, size_t s, size_t t)
{
	t_hmem	new;

	new.data = NULL;
	new.size = 0;
	if (s > src.size || s > t)
		return (new);
	else if (t > src.size)
		t = src.size;
	new.data = src.data;
	new.data += s;
	new.size = t - s;
	return (new);
}
