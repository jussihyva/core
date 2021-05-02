/*******************************************************************************
 * Add a node to n to graph g. New adjacency lists in and out are created for
 * the node, after which the node is added into the nodes list in the graph.
 *
 * @param g Source graph
 * @param n Node to be added
 * @return Index of the node added on success or -1 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_add_node(t_graph *g, t_graph_node n)
{
	n.out = arr_new(1, sizeof(t_graph_edge));
	n.in = arr_new(1, sizeof(t_graph_edge));
	if (!(arr_add_last(&g->nodes, &n)))
		return (-1);
	return ((ssize_t)g->nodes.len - 1);
}
