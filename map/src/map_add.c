#include "../inc/map.h"

ssize_t	map_add(t_map *dst, void *src, const char *key)
{
	uint64_t	hash_key;
	double		treshold;
	t_map_node	new_node;
	uint64_t	probe;
	size_t		i;

	new_node.data = src;
	new_node.key = key;
	treshold = dst->load_factor * (double)dst->capacity - 1;
	if (dst->count >= (uint64_t)treshold)
		map_grow(dst);
	hash_key = dst->hash(key);
	probe = 0;
	i = 0;
	while (!map_null_node(&dst->node[(hash_key + probe) % dst->capacity]))
	{
		probe = dst->probe(i);
		i++;
	}
	dst->node[(hash_key + probe) % dst->capacity] = new_node;
	dst->count++;
	return (CR_SUCCESS);
}
