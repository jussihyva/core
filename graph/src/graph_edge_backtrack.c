/******************************************************************************
 *
 * \brief Backtrack edges and store nodes in a path.
 *
 * Traverses a list of edges from the node to the first node assuming that
 * the sink node is the destination node of the last edge in the list. If `f`
 * is not NULL, will execute f on each traversed edge. This can be used to
 * update edge validity or attributes. Can also stop the backtracking by
 * returning 0 from f.
 *
 * \param edges List of edges as returned from breadth first search.
 *
 * \return A node path.
 *
 *****************************************************************************/

#include "../inc/graph.h"

t_nodes	graph_edge_backtrack(
	t_edges *edges,
	ssize_t (*f)(t_graph_edge *))
{
	t_nodes			path;
	t_graph_node	*v;
	t_graph_edge	*e;
	size_t			i;

	path = arr_new(1, sizeof(t_graph_node));
	e = arr_get_last(edges);
	if (f && !(f(e)))
		return (path);
	v = e->u;
	arr_add_mult(&path, 2, e->u, e->v);
	i = edges->len;
	while (i--)
	{
		e = arr_get(edges, i);
		if (s_cmp(e->v->key, v->key) == 0)
		{
			if (f && !(f(e)))
				return (path);
			arr_add_first(&path, e->u);
			v = e->u;
		}
	}
	return (path);
}
