/**
 *
 * \authors Julius Koskela
 *
 * \brief Depth first search on a directed graph.
 *
 * Performs a depth first search on a graph saving the result as edges
 * put into an array. If NULL is passed as destination, will search the
 * whole graph. Checks of edges are valid as well and won't traverse edges
 * that are marked as invalid. This is helpful with max flow for example.
 *
 * \param g Source graph.
 * \param s_name Source node name.
 * \param t_name Sink node name.
 *
 * \return A list of edges.
 *
 */

#include "../inc/digraph.h"

static void	digraph_depth_first_search_loop(
	t_parray *res,
	t_digraph_node *v,
	t_digraph_node *t)
{
	t_digraph_edge	*e;
	t_size			i;

	v->valid = 0;
	i = FALSE;
	while (i < v->e_out.len)
	{
		e = parr_get(&v->e_out, i);
		if (e->valid && e->v->valid)
		{
			parr_add_last(res, e);
			digraph_depth_first_search_loop(res, e->v, t);
		}
		if (t && s_cmp(v->name, t->name) == 0)
			return ;
		i++;
	}
	return ;
}

t_bool	digraph_depth_first_search(
		t_digraph *src,
		t_digraph_edge_set *dst,
		const char *s_name,
		const char *t_name)
{
	t_parray			queue;
	t_digraph_node	*s;
	t_digraph_node	*t;

	s = digraph_find_node(src, s_name);
	t = digraph_find_node(src, t_name);
	if (!s)
		return (FALSE);
	parr_new(&queue, 1);
	parr_add_last(&queue, s);
	digraph_depth_first_search_loop(&dst->edges, s, t);
	parr_free(&queue);
	map_iter(&src->nodes, digraph_node_reset);
	return (TRUE);
}
