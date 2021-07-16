#include "../inc/map.h"
#include "../../../inc/core.h"

void	map_free(t_map *src)
{
	t_size		i;

	i = 0;
	while (i < src->capacity)
	{
		free((void *)src->node[i].key);
		i++;
	}
	free(src->node);
	*src = (t_map){NULL, 0, 0, 0.0, NULL, NULL, NULL};
}
