#include "../../inc/core.h"

void	map_iter(t_map *src, ssize_t (*f)(void *, size_t))
{
	size_t	i;

	if (!src || !f)
		return ;
	i = 0;
	while (i < src->capacity)
	{
		if (!map_null_node(&src->node[i]))
			if (f(src->node[i].data, i) < 0)
				return ;
		i++;
	}
}
