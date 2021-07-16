///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Add node to a map.
///
/// Adds a new node to a map at a hashed position indicated by key. key is
/// used to retrieve a value from the map. If there is already an item with
/// the same key, returns CR_ERROR_BOUNDS. To update use map_update instead.
///
/// \param dst Destination map.
/// \param val Value to be added to the node.
/// \param key Key identifier of the node.
///
/// \return CR_SUCCESS or negative error code < 0.
///
///////////////////////////////////////////////////////////////////////////////

#include "../../../inc/core.h"

static t_uint64	map_threshold(t_map *map)
{
	return ((t_uint64)(map->load_factor * (double)map->capacity - 1));
}

t_ssize	map_add(t_map *dst, void *val, const char *key)
{
	t_uint64	hash_key;
	t_map_node	new_node;
	t_map_node	tmp;
	t_uint64	probe;
	t_size		i;

	if (!key || !val || map_null(dst))
		return (CR_FAIL);
	new_node.data = val;
	new_node.key = key;
	new_node.tombstone = FALSE;
	if (dst->count >= map_threshold(dst))
		map_grow(dst);
	hash_key = dst->hash(key);
	probe = 0;
	i = 0;
	while (1)
	{
		tmp = dst->node[(hash_key + probe) % dst->capacity];
		if (tmp.tombstone == TRUE)
			break ;
		if (map_null_node(&tmp) == TRUE)
			break ;
		if (s_cmp(tmp.key, key) == 0)
			return (CR_ERROR_BOUNDS);
		probe = dst->probe(i);
		i++;
	}
	dst->node[(hash_key + probe) % dst->capacity] = new_node;
	dst->count++;
	return (CR_SUCCESS);
}
