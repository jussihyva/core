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

#include "../../../inc/core.h"

t_ret	map_del(t_map *src, const char *key)
{
	t_uint64	hash_key;
	t_uint64	probe;
	t_map_node	*node;
	t_size		i;

	hash_key = src->hash(key);
	probe = 0;
	i = 0;
	while (1)
	{
		node = &src->node[(hash_key + probe) % src->capacity];
		if (node->key == NULL && node->tombstone == FALSE)
			break ;
		if (node->key && s_cmp(node->key, key) == 0)
		{
			free((char *)node->key);
			*node = (t_map_node){NULL, NULL, TRUE};
			src->count--;
			return (i);
		}
		probe = src->probe(i);
		i++;
	}
	return (CR_ERROR_BOUNDS);
}
