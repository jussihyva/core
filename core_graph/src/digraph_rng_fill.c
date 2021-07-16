///////////////////////////////////////////////////////////////////////////////
///
/// digraph_rng_fill.c
///
/// \authors Julius Koskela
///
/// \brief Fill graph with random data.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

t_bool	digraph_rng_fill(
		t_digraph *src,
		t_size ncount,
		t_size ecount)
{
	t_digraph_node_set	col;
	t_digraph_node		*u;
	t_digraph_node		*v;
	t_size				rng_u;
	t_size				rng_v;
	char				*rng_name;
	t_size	i;

	if (ecount > ncount * ncount - ncount)
		return (FALSE);
	i = 0;
	while (i < ncount)
	{
		rng_name = malloc(4);
		rng_string(rng_name, 3);
		if (digraph_add_node(src, (const char *)rng_name, NULL))
			i++;
		free(rng_name);
	}
	digraph_new_node_set(&col);
	digraph_collect_nodes(src, &col);
	i = 0;
	while (i < ecount)
	{
		rng_u = rng_range(0, col.nodes.len);
		rng_v = rng_range(0, col.nodes.len);
		u = parr_get(&col.nodes, rng_u);
		v = parr_get(&col.nodes, rng_v);
		if (u && v && s_cmp(u->name, v->name) != 0)
		{
			if (digraph_add_edge(src, u->name, v->name, NULL))
				i++;
		}
	}
	digraph_free_node_set(&col);
	return (TRUE);
}
