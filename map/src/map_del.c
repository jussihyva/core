/*******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/map.h"

ssize_t	map_del(t_map *src, const char *key)
{
	uint64_t	hash_key;
	uint64_t	probe;
	size_t		i;

	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (1)
	{
		if (map_null_node(&src->node[(hash_key + probe) % src->capacity]))
			return (-1);
		if (s_cmp(src->node[(hash_key + probe) % src->capacity].key, key) == 0)
			src->node[(hash_key + probe) % src->capacity] = CR_MAP_NULL_NODE;
		probe = src->probe(i);
		i++;
	}
	return (CR_SUCCESS);
}
