#include "../inc/map.h"

ssize_t	map_null_node(t_map_node *n)
{
	if (memcmp(n, &CR_MAP_NULL_NODE, sizeof(t_map_node)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}