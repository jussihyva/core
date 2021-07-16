///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print an adjacency matrix.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

void	digraph_print_edge_set_dot(
		t_digraph_edge_set *src)
{
	t_digraph_edge	*e;
	t_size		i;

	i = 0;
	while (i < src->edges.len)
	{
		e = parr_get(&src->edges, i);
		print("%-5s -> %-5s\n", e->u->name, e->v->name);
		i++;
	}
}
