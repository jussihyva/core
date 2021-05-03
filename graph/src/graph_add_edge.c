#include "../inc/graph.h"

ssize_t graph_add_edge(t_graph *g, ssize_t src_id,
		ssize_t dst_id, void *attr)
{
	t_graph_edge	e;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = graph_find_node(g, src_id);
	dst = graph_find_node(g, dst_id);
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
