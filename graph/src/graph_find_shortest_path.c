/*******************************************************************************
 * \brief Find a shortest path between source and sink node.
 * \param spath An array to store the shortest path. Has to be of type
 * t_graph_node.
 * \param source The source node from which the search will be started from.
 * \param sink A sink node to which we are finding the path to.
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_find_shortest_path(
		t_arr *spath,
		t_graph_node *source,
		t_graph_node *sink)
{
	t_arr	edge_list;

	edge_list = arr_new(1, sizeof(t_graph_edge));
	graph_bfs(&edge_list, source, sink);
	graph_edge_backtrack(spath, &edge_list);
	arr_free(&edge_list);
	return (CR_SUCCESS);
}
