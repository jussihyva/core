///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Delete edge from a directed graph.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

t_bool	digraph_del_edge(
		t_digraph *src,
		const char *u_name,
		const char *v_name)
{
	t_digraph_node	*u;
	t_digraph_node	*v;
	t_digraph_edge	*e;
	t_size	i;

	u = digraph_find_node(src, u_name);
	v = digraph_find_node(src, v_name);
	i = 0;
	while (i < u->e_out.len)
	{
		e = parr_get(&u->e_out, i);
		if (e && e->v == v)
		{
			parr_del(&u->e_out, i);
			free(e);
			src->ecount--;
			return (TRUE);
		}
		i++;
	}
	return (FALSE);
}
