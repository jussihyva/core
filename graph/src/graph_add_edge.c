#include "../inc/graph.h"

ssize_t graph_add_edge(t_graph *g, size_t src_index,
		size_t dst_index, void *attr)
{
	t_graph_edge	e;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = arr_get(&g->nodes, src_index);
	dst = arr_get(&g->nodes, dst_index);
	if (!src || !dst)
		return (-1);
	e.src = src;
	e.dst = dst;
	e.attr = attr;
	if (!(arr_add_last(&src->out, &e)))
		return (-1);
	if (!(arr_add_last(&dst->in, &e)))
		return (-1);
	return (CR_SUCCESS);
}
