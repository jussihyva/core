/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/map.h"
#include "../../inc/core.h"

void	*map_get(t_map *src, const char *key)
{
	uint64_t	hash_key;
	uint64_t	probe;
	size_t		i;

	if (!key)
		return (NULL);
	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (i < src->count)
	{
		if (src->node[(hash_key + probe)
				% src->capacity].key
			&& s_cmp(src->node[(hash_key + probe)
					% src->capacity].key,
				key) == 0)
			return (src->node[(hash_key + probe) % src->capacity].data);
		probe = src->probe(i);
		i++;
	}
	return (NULL);
}
