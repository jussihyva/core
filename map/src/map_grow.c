/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../inc/core.h"

static ssize_t	map_grow_add(t_map *dst, void *src, const char *key)
{
	uint64_t	hash_key;
	t_map_node	new_node;
	uint64_t	probe;
	size_t		i;

	new_node.data = src;
	new_node.key = key;
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

ssize_t	map_grow(t_map *src)
{
	t_map	new;
	size_t	i;

	new.capacity = src->resize(src->capacity + 1);
	new.count = 0;
	new.hash = src->hash;
	new.load_factor = src->load_factor;
	new.probe = src->probe;
	new.resize = src->resize;
	new.node = (t_map_node *)mem_alloc(sizeof(t_map_node) * new.capacity);
	if (!new.node)
	{
		print("Allocation failed in function: map_grow!\n");
		exit(-1);
	}
	i = 0;
	while (i < src->capacity)
	{
		if (!map_null_node(&src->node[i]))
			map_grow_add(&new, src->node[i].data, src->node[i].key);
		i++;
	}
	free(src->node);
	*src = new;
	return (CR_SUCCESS);
}
