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
		if (arr_find_by(dfs_queue, dst_node, graph_cmp_nodes) == -1)
		{
			arr_add_last(dfs_queue, dst_node);
			arr_add_last(res_edges, curr_edge);
			graph_dfs_loop(res_edges, dfs_queue, dst_node, sink);
		}
		if (sink && s_cmp(dst_node->key, sink->key) == 0)
			return (CR_SUCCESS);
		i++;
	}
	return (CR_SUCCESS);
}

t_arr graph_dfs(
		t_graph *g,
		const char *src_key,
		const char *dst_key)
{
	t_arr			dfs_queue;
	t_arr			res_edges;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = graph_find_node(g, src_key);
	dst = NULL;
	if (dst_key)
		dst = graph_find_node(g, dst_key);
	res_edges = arr_new(1, sizeof(t_graph_edge));
	dfs_queue = arr_new(1, sizeof(t_graph_node));
	if (!(arr_add_last(&dfs_queue, src)))
		return (CR_ARR_NULL);
	if (!(graph_dfs_loop(&res_edges, &dfs_queue, src, dst)))
		return (CR_ARR_NULL);
	arr_free(&dfs_queue);
	return (res_edges);
}
