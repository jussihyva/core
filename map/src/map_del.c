/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Delete a node from a map.
 *
 * \param src Destination map.
 * \param key Key identifier of the node.
 *
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../../inc/core.h"

ssize_t	map_del(t_map *src, const char *key)
{
	uint64_t	hash_key;
	uint64_t	probe;
	size_t		i;

	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (i < src->count)
	{
		if (src->node[(hash_key + probe)
				% src->capacity].key
			&& s_cmp(src->node[(hash_key + probe)
					% src->capacity].key, key) == 0)
		{
			src->node[(hash_key + probe) % src->capacity]
				= CR_MAP_NULL_NODE;
			return (i);
		}
		probe = src->probe(i);
		i++;
	}
	return (0);
}
