/**
 *
 * \authors Julius Koskela
 *
 * \brief Backtrack edges and store nodes in a path.
 *
 * Traverses a list of edges from the sink node to the first node assuming that
 * the sink node is the destination node of the last edge in the list. If `f`
 * is not NULL, will execute f on each traversed edge. This can be used to
 * update edge validity or attributes. Can also stop the backtracking by
 * returning 0 from f.
 *
 * \param edges List of edges as returned from breadth first search.
 *
 * \return A node path.
 *
 */

#include "../inc/digraph.h"

t_bool	digraph_edge_set_backtrack(
	t_digraph_edge_set *src,
	t_digraph_node_set *dst,
	const char *t_name,
	t_ssize (*f)(t_digraph_edge *))
{
	t_digraph_node		*v;
	t_digraph_edge		*e;
	t_size		i;

	e = parr_get_last(&src->edges);
	if ((t_name && s_cmp(t_name, e->v->name)) || (f && !f(e)))
		return (FALSE);
	v = e->u;
	parr_add_mult(&dst->nodes, 2, e->u, e->v);
	i = src->edges.len;
	while (i--)
	{
		e = parr_get(&src->edges, i);
		if (s_cmp(e->v->name, v->name) == 0)
		{
			if (f && (f(e) < 0))
				return (TRUE);
			parr_add_first(&dst->nodes, e->u);
			v = e->u;
		}
	}
	return (TRUE);
}
