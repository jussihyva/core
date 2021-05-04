/*******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_dfs_loop(
		t_arr *res_edges,
		t_arr *dfs_queue,
		t_graph_node *curr,
		t_graph_node *sink)
{
	t_graph_edge	*curr_edge;
	t_graph_node	*dst_node;
	size_t			i;

	i = 0;
	while (i < curr->out.len)
	{
		curr_edge = arr_get(&curr->out, i);
		dst_node = curr_edge->dst;
		if (!(arr_find_by(dfs_queue, dst_node, graph_cmp_nodes)))
		{
			arr_add_last(dfs_queue, dst_node);
			arr_add_last(res_edges, curr_edge);
			graph_dfs_loop(res_edges, dfs_queue, dst_node, sink);
		}
		if (dst_node->id == sink->id)
			return (CR_SUCCESS);
		i++;
	}
	return (CR_SUCCESS);
}

ssize_t graph_dfs(
		t_arr *res_edges,
		t_graph_node *source,
		t_graph_node *sink)
{
	t_arr	dfs_queue;

	dfs_queue = arr_new(1, sizeof(t_graph_node));
	if (!(arr_add_last(&dfs_queue, source)))
		return (CR_FAIL);
	if (!(graph_dfs_loop(res_edges, &dfs_queue, source, sink)))
		return (CR_FAIL);
	arr_free(&dfs_queue);
	return (CR_SUCCESS);
}
