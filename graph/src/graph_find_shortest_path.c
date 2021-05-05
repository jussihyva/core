/*******************************************************************************
 * \brief Find a shortest path between source and sink node.
 * \param spath An array to store the shortest path. Has to be of type
 * t_graph_node.
 * \param source The source node from which the search will be started from.
 * \param sink A sink node to which we are finding the path to.
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

t_arr graph_find_shortest_path(
		t_graph *g,
		const char *src_key,
		const char *dst_key)
{
	t_arr	edge_list;
	t_arr	spath;

	spath = arr_new(1, sizeof(t_graph_node));
	edge_list = graph_bfs(g, src_key, dst_key);
	graph_edge_backtrack(&spath, &edge_list);
	arr_free(&edge_list);
	return (spath);
}
