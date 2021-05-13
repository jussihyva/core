/**
 *
 * \authors Julius Koskela
 *
 * \brief Breadth first search on a graph.
 *
 * Performs a breadth first search on a graph saving the result as edges
 * put into an array. If NULL is passed as destination, will search the
 * whole graph. Checks of edges are valid as well and won't traverse edges
 * that are marked as invalid. This is helpful with max flow for example.
 *
 * \param g Source graph.
 * \param src_key Key of the root of the search.
 * \param dst_key Key of the destination of the search. If NULL is passed
 * will seacrh the whole graph.
 *
 * \return An array containing a list of edges.
 *
 */

#include "../inc/graph.h"

static ssize_t	graph_iter_edges(
	t_edges *res,
	t_nodes *queue,
	t_graph_node *v,
	t_graph_node *t)
{
	t_graph_edge	*curr_edge;
	size_t			i;

	i = 0;
	while (i < v->out.len)
	{
		curr_edge = arr_get(&v->out, i);
		if (curr_edge->valid && curr_edge->v->valid)
		{
			arr_add_last(res, curr_edge);
			arr_add_last(queue, curr_edge->v);
			if (t && s_cmp(curr_edge->v->key, t->key) == 0)
				return (CR_SUCCESS);
		}
		i++;
	}
	return (CR_FAIL);
}

static ssize_t	graph_bfs_loop(
	t_edges *res,
	t_graph_node *s,
	t_graph_node *t)
{
	t_nodes			queue;
	t_graph_node	*v;
	size_t			i;

	queue = arr_new(1, sizeof(t_graph_node));
	arr_add_last(&queue, s);
	s->valid = 0;
	i = 0;
	while (i < queue.len)
	{
		v = arr_get(&queue, i);
		v->valid = 0;
		if (graph_iter_edges(res, &queue, v, t))
			return (CR_SUCCESS);
		i++;
	}
	arr_free(&queue);
	return (CR_SUCCESS);
}

t_edges	graph_bfs(t_graph *g, const char *s_key, const char *t_key)
{
	t_edges			res;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(g, s_key);
	t = graph_find_node(g, t_key);
	if (!s)
		return (CR_ARR_NULL);
	res = arr_new(1, sizeof(t_graph_edge));
	graph_bfs_loop(&res, s, t);
	map_iter(g, graph_node_valid);
	return (res);
}
