#include "../inc/map.h"
#include "../../../inc/core.h"

void	map_print(t_map *m)
{
	t_size	i;

	i = 0;
	while (i < m->capacity)
	{
		if (i > 0 && i % 16 == 0)
			print("\n");
		if (map_null_node(&m->node[i]) == TRUE)
			print("[x]");
		else if (m->node[i].tombstone == TRUE)
			print("[T]");
		else
			print("[$]");
		i++;
	}
}
