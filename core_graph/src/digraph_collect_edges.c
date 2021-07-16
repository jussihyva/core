///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Collect edges from a directed graph.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

t_bool	digraph_collect_edges(
		t_digraph *src,
		t_digraph_edge_set *dst)
{
	t_digraph_node_set	n;
	t_digraph_node		*node;
	t_size			i;


	digraph_new_node_set(&n);
	digraph_collect_nodes(src, &n);
	i = 0;
	while (i < n.nodes.len)
	{
		node = parr_get(&n.nodes, i);
		digraph_collect_outbound_edges(node, dst);
		i++;
	}
	digraph_free_node_set(&n);
	return (TRUE);
}
