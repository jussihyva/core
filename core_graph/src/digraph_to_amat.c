///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Convert directed graph to an adjacency matrix.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

static t_ssize	get_row_index(
		t_parray *nodes,
		t_digraph_node *v)
{
	t_digraph_node	*nodes_v;
	t_size	i;

	i = 0;
	while (i < nodes->len)
	{
		nodes_v = parr_get(nodes, i);
		if (s_cmp(nodes_v->name, v->name) == 0)
			return (i);
		i++;
	}
	return (-1);
}

static t_bool	create_row(
		t_bool *row,
		t_parray *nodes,
		t_digraph_node *v)
{
	t_digraph_edge	*e;
	t_ssize		row_index;
	t_size		i;

	i = 0;
	while (i < v->e_out.len)
	{
		e = parr_get(&v->e_out, i);
		row_index = get_row_index(nodes, e->v);
		if (row_index > -1)
			row[row_index] = TRUE;
		i++;
	}
	return (TRUE);
}

t_bool	digraph_to_amat(
		t_digraph *src,
		t_digraph_amat *dst)
{
	t_digraph_node		*v;
	t_size			i;

	digraph_collect_nodes(src, &dst->all);
	if (dst->all.nodes.len != dst->size)
		return (FALSE);
	i = 0;
	while (i < dst->size)
	{
		v = parr_get(&dst->all.nodes, i);
		create_row(&dst->matrix[i * dst->size], &dst->all.nodes, v);
		i++;
	}
	return (TRUE);
}
