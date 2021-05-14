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
	t_parray *res,
	t_nodes *queue,
	t_graph_node *t,
	size_t queue_index)
{
	t_graph_edge	*e;
	t_graph_node	*v;
	size_t			i;

	v = arr_get(queue, queue_index);
	i = 0;
	while (i < v->out.len)
	{
		e = arr_get(&v->out, i);
		if (!e)
			return (-1);
		if (e->valid && e->v->valid)
		{
			e->v->valid = false;
			parr_add_last(res, e);
			arr_add_last(queue, e->v);
			v = arr_get(queue, queue_index);
			if (t && s_cmp(e->v->key, t->key) == 0)
				return (true);
		}
		i++;
	}
	return (false);
}

static void	graph_bfs_loop(
	t_parray *res,
	t_graph_node *s,
	t_graph_node *t)
{
	t_nodes			queue;
	t_graph_node	*v;
	size_t			i;

	queue = arr_new(1, sizeof(t_graph_node));
	s->valid = false;
	arr_add_last(&queue, s);
	i = 0;
	while (i < queue.len)
	{
		v = arr_get(&queue, i);
		v->valid = false;
		if (graph_iter_edges(res, &queue, t, i))
		{
			arr_free(&queue);
			return ;
		}
		i++;
	}
	arr_free(&queue);
	return ;
}

t_parray	graph_bfs(t_graph *g, const char *s_key, const char *t_key)
{
	t_parray		res;
	t_graph_node	*s;
	t_graph_node	*t;

	s = graph_find_node(g, s_key);
	t = graph_find_node(g, t_key);
	if (!s)
		return (CR_PARR_NULL);
	res = parr_new(1);
	graph_bfs_loop(&res, s, t);
	map_iter(g, graph_node_valid);
	return (res);
}
