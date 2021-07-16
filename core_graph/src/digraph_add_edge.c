///////////////////////////////////////////////////////////////////////////////
///
/// digraph_add_edge.c
///
/// \authors Julius Koskela
///
/// \brief Add an edge to a directed graph.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

static t_bool	check_duplicate_edge(
		t_digraph_node *u,
		t_digraph_node *v)
{
	t_digraph_edge	*e;
	t_size		i;

	i = 0;
	while (i < u->e_out.len)
	{
		e = parr_get(&u->e_out, i);
		if (s_cmp(e->v->name, v->name) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_digraph_edge	*digraph_new_edge(
		t_digraph *g,
		t_digraph_node *u,
		t_digraph_node *v,
		t_attr_edge *attr)
{
	t_digraph_edge	*e;

	if (!u
		|| !v
		|| !digraph_find_node(g, u->name)
		|| !digraph_find_node(g, u->name))
		{
			return (NULL);
		}
	e = malloc(sizeof(t_digraph_edge));
	if (!e)
		return (NULL);
	e->attr = attr;
	e->u = u;
	e->v = v;
	e->valid = TRUE;
	return (e);
}

t_bool	digraph_add_edge(
		t_digraph *g,
		const char *u_name,
		const char *v_name,
		t_attr_edge *attr)
{
	t_digraph_edge	*e;
	t_digraph_node	*u;
	t_digraph_node	*v;

	u = digraph_find_node(g, u_name);
	v = digraph_find_node(g, v_name);
	if (!(check_duplicate_edge(u, v)))
		return (FALSE);
	if (!u || !v)
	{
		print("Trying to connect an edge with a non-existing node!\n");
		return (FALSE);
	}
	e = (t_digraph_edge *)malloc(sizeof(t_digraph_edge));
	if (!e)
		return (FALSE);
	e->u = u;
	e->v = v;
	e->valid = TRUE;
	e->attr = attr;
	parr_add_last(&u->e_out, e);
	parr_add_last(&v->e_in, e);
	g->ecount++;
	return (TRUE);
}
