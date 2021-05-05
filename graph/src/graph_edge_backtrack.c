/*******************************************************************************
 * \brief Backtrack edges in edge_list and store nodes in breadcrumbs.
 *
 * Traverses a list of edges from the node to the first node assuming that
 * the sink node is the destination node of the last edge in the list.
 *
 * \param breadcrumbs Traversed nodes.
 * \param edge_list List of edges as returned from breadth first search.
 * \return Distance of nodes travelled and -1 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_edge_backtrack(t_arr *breadcrums, t_arr *edge_list)
{
	t_graph_node	*curr_node;
	t_graph_edge	*curr_edge;
	ssize_t			dist;
	size_t			i;

	curr_edge = arr_get_last(edge_list);
	curr_node = curr_edge->src;
	arr_add_mult(breadcrums, 2, curr_edge->dst, curr_edge->src);
	dist = 0;
	i = edge_list->len;
	while (i--)
	{
		curr_edge = arr_get(edge_list, i);
		if (curr_edge->dst->id == curr_node->id)
		{
			arr_add_last(breadcrums, curr_edge->src);
			curr_node = curr_edge->src;
			dist++;
		}
	}
	return (dist);
}