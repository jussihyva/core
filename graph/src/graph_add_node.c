/*******************************************************************************
 * \brief Add a node n to graph g.
 *
 * New adjacency lists in and out are created for the node, after which the
 * node is added into the nodes list in the graph.
 *
 * \param g Source graph.
 * \param n Node to be added.
 * \return Index of the node added on success or -1 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_add_node(t_graph *g, t_graph_node *n)
{
	if (!(map_add(&g->nodes, n, n->key)))
		return (-1);
	return ((ssize_t)g->nodes.count);
}
