/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Add node to a map.
 *
 * Adds a new node to a map at a hashed position indicated by key. key is
 * used to retrieve a value from the map.
 *
 * \param dst Destination map.
 * \param val Value to be added to the node.
 * \param key Key identifier of the node.
 *
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../../inc/core.h"

static uint64_t	map_threshold(t_map *map)
{
	return ((uint64_t)(map->load_factor * (double)map->capacity - 1));
}

ssize_t	map_add(t_map *dst, void *val, const char *key)
{
	uint64_t	hash_key;
	t_map_node	new_node;
	uint64_t	probe;
	size_t		i;

	if (!key || !val || map_null(dst))
		return (CR_FAIL);
	new_node.data = val;
	new_node.key = key;
	if (dst->count >= map_threshold(dst))
		map_grow(dst);
	hash_key = dst->hash(key);
	probe = 0;
	i = 0;
	while (!map_null_node(&dst->node[(hash_key + probe) % dst->capacity]))
	{
		if (s_cmp(dst->node[(hash_key + probe) % dst->capacity].key, key) == 0)
			return (CR_FAIL);
		probe = dst->probe(i);
		i++;
	}
	dst->node[(hash_key + probe) % dst->capacity] = new_node;
	dst->count++;
	return (CR_SUCCESS);
}
