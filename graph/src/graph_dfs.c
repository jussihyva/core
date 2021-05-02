#include "../inc/graph.h"

ssize_t graph_dfs_loop(t_arr *dfs_queue, t_graph_node *curr)
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
			graph_dfs_loop(dfs_queue, dst_node);
		}
		i++;
	}
	return (CR_SUCCESS);
}

ssize_t graph_dfs(t_arr *dfs_queue, t_graph_node *root)
{
	if (!(arr_add_last(dfs_queue, root)))
		return (CR_FAIL);
	if (!(graph_dfs_loop(dfs_queue, root)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}
