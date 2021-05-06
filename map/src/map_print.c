#include "../inc/map.h"
#include "../../inc/core.h"

void	map_print(t_map *m)
{
	size_t	i;

	i = 0;
	while (i < m->capacity)
	{
		if (map_null_node(&m->node[i]))
			printf("[EMPTY]\n");
		else
			printf("%s\n", m->node[i].key);
		i++;
	}
}

