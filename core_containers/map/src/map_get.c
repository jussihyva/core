/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

void	*map_get(t_map *src, const char *key)
{
	t_map_node	node;
	t_uint64	hash_key;
	t_uint64	probe;
	t_size		i;

	if (!key)
		return (NULL);
	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (i < src->count)
	{
		node = src->node[(hash_key + probe) % src->capacity];
		if (map_null_node(&node) == TRUE)
			return (NULL);
		if (node.key && s_cmp(node.key, key) == 0)
			return (node.data);
		probe = src->probe(i);
		i++;
	}
	return (NULL);
}
