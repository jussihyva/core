/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../inc/core.h"

t_map	map_new(void)
{
	t_map	m;
	size_t	i;

	m.capacity = CR_MAP_START_CAPACITY;
	m.load_factor = CR_MAP_LOAD_FACTOR;
	m.hash = CR_MAP_HASH;
	m.probe = CR_MAP_PROBE;
	m.resize = CR_MAP_RESIZE;
	m.node = (t_map_node *)mem_alloc(sizeof(t_map_node) * m.capacity);
	if (!m.node)
	{
		printf("Allocation failed in function: map_new!\n");
		exit(-1);
	}
	i = 0;
	while (i < m.capacity)
	{
		m.node[i] = CR_MAP_NULL_NODE;
		i++;
	}
	m.count = 0;
	return (m);
}
