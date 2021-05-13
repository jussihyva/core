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

#include "../inc/graph.h"

t_array	graph_find_shortest_path(
		t_graph *g,
		const char *s_key,
		const char *t_key)
{
	t_edges	edges;
	t_nodes	path;

	edges = graph_bfs(g, s_key, t_key);
	path = graph_edge_backtrack(&edges, NULL);
	arr_free(&edges);
	return (path);
}
