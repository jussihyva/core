/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Breadth first search on a graph.
 *
 * Performs a breadth first search on a graph saving the result as edges
 * put into an array. If NULL is passed as destination, will search the
 * whole graph.
 *
 * \param g Source graph.
 * \param src_key Key of the root of the search.
 * \param dst_key Key of the destination of the search. If NULL is passed
 * will seacrh the whole graph.
 *
 * \return An array containing a list of edges.
 *
 ******************************************************************************/

#include "../inc/graph.h"

static ssize_t graph_bfs_loop(
		t_array *bfs_queue,
		t_array *res_edges,
		t_graph_node *sink,
		size_t queue_index)
{
	t_graph_node	*curr_node;
	t_graph_edge	*curr_edge;
	size_t			i;

	if (bfs_queue->len == queue_index)
		return (CR_SUCCESS);
	curr_node = arr_get(bfs_queue, queue_index);
	i = 0;
	while (i < curr_node->out.len)
	{
		curr_edge = arr_get(&curr_node->out, i);
		if ((arr_find_by(bfs_queue, curr_edge->dst, graph_cmp_nodes)) == -1)
		{
			if (!(arr_add_last(res_edges, curr_edge)))
				return (CR_FAIL);
			if (!(arr_add_last(bfs_queue, curr_edge->dst)))
				return (CR_FAIL);
			if (sink && s_cmp(curr_edge->dst->key, sink->key) == 0)
				return (CR_SUCCESS);
		}
		curr_node = arr_get(bfs_queue, queue_index);
		i++;
	}
	return (graph_bfs_loop(bfs_queue, res_edges, sink, queue_index + 1));
}

t_array graph_bfs(
		t_graph *g,
		const char *src_key,
		const char *dst_key)
{
	t_array			bfs_queue;
	t_array			res_edges;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = graph_find_node(g, src_key);
	dst = graph_find_node(g, dst_key);
	res_edges = arr_new(1, sizeof(t_graph_edge));
	bfs_queue = arr_new(1, sizeof(t_graph_node));
	if (!(arr_add_last(&bfs_queue, src)))
		return (CR_ARR_NULL);
	if (!(graph_bfs_loop(&bfs_queue, &res_edges, dst, 0)))
		return (CR_ARR_NULL);
	arr_free(&bfs_queue);
	return (res_edges);
}
