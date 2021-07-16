/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/digraph.h"

t_bool	digraph_collect_outbound_edges(
		t_digraph_node *src,
		t_digraph_edge_set *dst)
{
	t_digraph_edge	*e;
	t_size		i;

	i = 0;
	while (i < src->e_out.len)
	{
		e = parr_get(&src->e_out, i);
		parr_add_last(&dst->edges, e);
		i++;
	}
	return (TRUE);
}
