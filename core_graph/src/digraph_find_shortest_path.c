/**
 *
 * \brief Find a shortest path between source and sink node.
 *
 * \param spath An array to store the shortest path. Has to be of type
 * t_graph_node.
 * \param source The source node from which the search will be started from.
 * \param sink A sink node to which we are finding the path to.
 *
 * \return 1 on success 0 on failure.
 *
 */

#include "../inc/digraph.h"

t_bool	digraph_find_shortest_path(
	t_digraph *src,
	t_digraph_node_set *dst,
	const char *s_name,
	const char *t_name)
{
	t_digraph_edge_set	edges;

	digraph_new_edge_set(&edges);
	if (!(digraph_breadth_first_search(src, &edges, s_name, t_name)))
		return (FALSE);
	digraph_edge_set_backtrack(&edges, dst, t_name, NULL);
	digraph_free_edge_set(&edges);
	return (TRUE);
}
