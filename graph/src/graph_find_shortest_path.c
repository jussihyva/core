#include "../inc/graph.h"

static ssize_t graph_bfs_int_loop(t_arr *bfs_queue, t_arr *edge_list, t_graph_node *sink, size_t queue_index)
{
	t_graph_node	*curr;
	t_graph_edge	*curr_edge;
	t_graph_node	*dst_node;
	size_t			i;
	size_t			len;
	

	if (bfs_queue->len == queue_index)
	{
		printf("No sink found!\n");
		return (CR_FAIL);
	}
	curr = arr_get(bfs_queue, queue_index);
	len = curr->out.len;
	i = 0;
	while (i < len)
	{
		curr_edge = arr_get(&curr->out, i);
		if (!curr_edge)
			break ;
		dst_node = curr_edge->dst;
		if (!(arr_find_by(bfs_queue, dst_node, graph_cmp_nodes)))
		{
			if (!(arr_add_last(edge_list, curr_edge)))
				return (CR_FAIL);
			if (!(arr_add_last(bfs_queue, dst_node)))
				return (CR_FAIL);
			if (dst_node->id == SINK)
				return (CR_SUCCESS);
		}
		i++;
	}
	return (graph_bfs_int_loop(bfs_queue, edge_list, sink, queue_index + 1));
}

static size_t graph_construct_path(t_arr *spath, t_arr *edge_list)
{
	t_graph_edge	*curr_edge;
	t_graph_node	*curr_node;
	size_t			i;

	curr_edge = arr_get_last(edge_list);
	curr_node = curr_edge->src;
	arr_add_mult(spath, 2, curr_edge->dst, curr_edge->src);
	i = edge_list->len - 1;
	while (i--)
	{
		curr_edge = arr_get(edge_list, i);
		if (curr_edge->dst->id == curr_node->id)
		{
			arr_add_last(spath, curr_edge->src);
			curr_node = curr_edge->src;
		}
	}
	return (CR_SUCCESS);
}

static size_t graph_bfs_int(t_arr *edge_list, t_graph_node *source, t_graph_node *sink)
{
    t_arr   bfs_queue;

    bfs_queue = arr_new(1, sizeof(t_graph_node));
	if (!(arr_add_last(&bfs_queue, source)))
		return (CR_FAIL);
	if (!(graph_bfs_int_loop(&bfs_queue, edge_list, sink, 0)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

ssize_t graph_find_shortest_path(t_arr *spath, t_graph_node *source, t_graph_node *sink)
{
	t_arr	edge_list;

	edge_list = arr_new(1, sizeof(t_graph_edge));
	graph_bfs_int(&edge_list, source, sink);
	graph_construct_path(spath, &edge_list);
	return (CR_SUCCESS);
}
