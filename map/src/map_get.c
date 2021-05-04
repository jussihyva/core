#include "../inc/map.h"

ssize_t	map_get(void *dst, t_map *src, const char *key)
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
			break ;
		if (s_cmp(src->node[(hash_key + probe) % src->capacity].key, key) == 0)
			break ;
		probe = src->probe(i);
		i++;
	}
	dst = src->node[(hash_key + probe) % src->capacity].data;
	if (dst)
		return (CR_SUCCESS);
	return (CR_FAIL);
}