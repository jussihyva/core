/******************************************************************************
 * \brief Find all root nodes from a directed graph.
 * \param g Source graph.
 * \param roots An array to store the root nodes.
 * \return 1 on success 0 on failure.
 *****************************************************************************/

#include "../inc/digraph.h"

t_bool	digraph_find_roots(
			t_digraph *src,
			t_digraph_node_set *dst)
{
	t_map_node	m_node;
	t_digraph_node	*g_node;
	t_size		i;

	i = 0;
	while (i < src->nodes.count)
	{
		m_node = src->nodes.node[i];
		if (m_node.key)
		{
			g_node = (t_digraph_node *)m_node.data;
			if (g_node->e_in.len == 0)
				parr_add_last(&dst->nodes, g_node);
		}
		i++;
	}
	return (TRUE);
}
