/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/graph.h"

ssize_t	graph_add_edge(
		t_graph *g,
		const char *src_key,
		const char *dst_key,
		void *attr)
{
	t_graph_edge	e;
	t_graph_node	*src;
	t_graph_node	*dst;

	src = graph_find_node(g, src_key);
	dst = graph_find_node(g, dst_key);
	if (!src || !dst)
	{
		printf("Trying to connect an edge with a non-existing node!\n");
		return (-1);
	}
	e.src = src;
	e.dst = dst;
	e.attr = attr;
	arr_add_last(&src->out, &e);
	arr_add_last(&dst->in, &e);
	return (CR_SUCCESS);
}
