///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
///
/// \brief Breadth first search on a directed graph.
///
/// Performs a breadth first search on a graph saving the result as edges
/// put into an array. If NULL is passed as destination, will search the
/// whole graph. Checks of edges are valid as well and won't traverse edges
/// that are marked as invalid. This is helpful with max flow for example.
///
/// \param g Source graph.
/// \param src_name name of the root of the search.
/// \param dst_name name of the destination of the search. If NULL is passed
/// will seacrh the whole graph.
///
/// \return An array containing a list of edges.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

// Iterate over outgoing edges of the next node in the queue. We don't delete
// nodes, but keep queue index which denotes the next node to be dequeued.

static t_ssize	digraph_iter_edges(
	t_parray *dst,
	t_parray *queue,
	t_digraph_node *t,
	t_size bottom)
{
	t_digraph_edge	*e;
	t_digraph_node	*v;
	t_size		i;

	v = parr_get(queue, bottom);
	i = 0;
	while (i < v->e_out.len)
	{
		e = parr_get(&v->e_out, i);
		if (!e)
			return (FALSE);
		if (e->valid && e->v->valid)
		{
			e->v->valid = FALSE;
			parr_add_last(dst, e);
			parr_add_last(queue, e->v);
			if (t && e->v == t)
				return (TRUE);
		}
		i++;
	}
	return (FALSE);
}

// Put the source node s as first in the queue and start looping over the
// queue. On each iteration we push the unvisited nodes from the outgoing
// edges of the current node to the top of the queue.

static void	digraph_breadth_first_search_loop(
	t_parray *dst,
	t_digraph_node *s,
	t_digraph_node *t,
	t_parray *queue)
{
	t_digraph_node		*v;
	t_size			i;

	s->valid = FALSE;
	parr_add_last(queue, s);
	i = 0;
	while (i < queue->len)
	{
		v = parr_get(queue, i);
		v->valid = FALSE;
		if (digraph_iter_edges(dst, queue, t, i))
			return ;
		i++;
	}
}

// Find the nodes from the graph and start the search loop. We accept `t_name`
// as NULL since that is the equivalent of searching the whole graph from
// `s_name`. After finished reset the valid attribute of each node to unlock
// the nodes.

t_bool	digraph_breadth_first_search(
		t_digraph *src,
		t_digraph_edge_set *dst,
		const char *s_name,
		const char *t_name)
{
	t_digraph_node	*s;
	t_digraph_node	*t;
	t_parray	queue;

	s = digraph_find_node(src, s_name);
	t = digraph_find_node(src, t_name);
	if (!s)
		return (FALSE);
	parr_new(&queue, src->ncount);
	digraph_breadth_first_search_loop(&dst->edges, s, t, &queue);
	map_iter(&src->nodes, digraph_node_reset);
	parr_free(&queue);
	return (TRUE);
}

///////////////////////////////////////////////////////////////////////////////
