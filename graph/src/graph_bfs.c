#include "../inc/graph.h"

ssize_t graph_bfs_loop(t_arr *bfs_queue,
						t_graph_node *curr,
						size_t curr_index)
{
	t_graph_edge	*curr_edge;
	t_graph_node	*dst_node;
	size_t			i;

	i = 0;
	size_t	len = curr->out.len;
	while (i < len)
	{
		curr_edge = arr_get(&curr->out, i);
		if (!curr_edge)
			break ;
		dst_node = curr_edge->dst;
		if (!(arr_find_by(bfs_queue, dst_node, graph_cmp_nodes)))
		{
			if (!(arr_add_last(bfs_queue, dst_node)))
				return (CR_FAIL);
		}
		i++;
	}
	if (curr_index < bfs_queue->len)
	{
		dst_node = arr_get(bfs_queue, curr_index);
		graph_bfs_loop(bfs_queue, dst_node, curr_index + 1);
	}
	return (CR_SUCCESS);
}

ssize_t graph_bfs(t_arr *bfs_queue, t_graph_node *root)
{
	if (!(arr_add_last(bfs_queue, root)))
		return (CR_FAIL);
	if (!(graph_bfs_loop(bfs_queue, root, 1)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}
