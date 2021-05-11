#include "../inc/map.h"
#include "../../inc/core.h"

ssize_t	map_free(t_map *src)
{
	free(src->node);
	*src = CR_MAP_NULL;
	return (CR_SUCCESS);
}
