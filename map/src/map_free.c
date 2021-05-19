#include "../inc/map.h"
#include "../../inc/core.h"

t_ssize	map_free(t_map *src)
{
	free(src->node);
	*src = CR_MAP_NULL;
	return (CR_SUCCESS);
}
