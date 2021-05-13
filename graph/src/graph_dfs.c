/**
 *
 * \authors Julius Koskela
 *
 * \brief Depth first search on a directed graph.
 *
 * \param g Source graph.
 * \param s_key Source node key.
 * \param t_key Sink node key.
 *
 * \return A list of edges.
 *
 */

#include "../inc/graph.h"

static ssize_t	graph_dfs_loop(
	t_edges *res,
	t_graph_node *v,
	t_graph_node *t)
{
	t_graph_edge	*curr_edge;
	size_t			i;

	v->valid = 0;
	i = 0;
	while (i < v->out.len)
	{
		curr_edge = arr_get(&v->out, i);
		if (curr_edge->valid && curr_edge->v->valid)
		{
			arr_add_last(res, curr_edge);
			graph_dfs_loop(res, curr_edge->v, t);
		}
		if (t && s_cmp(v->key, t->key) == 0)
			return (CR_SUCCESS);
		i++;
	}
	return (CR_SUCCESS);
}

t_edges	graph_dfs(t_graph *g, const char *s_key, const char *t_key)
{
	t_nodes			queue;
	t_edges			res;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(g, s_key);
	t = graph_find_node(g, t_key);
	if (!s)
		return (CR_ARR_NULL);
	res = arr_new(1, sizeof(t_graph_edge));
	queue = arr_new(1, sizeof(t_graph_node));
	arr_add_last(&queue, s);
	graph_dfs_loop(&res, s, t);
	arr_free(&queue);
	map_iter(g, graph_node_valid);
	return (res);
}
