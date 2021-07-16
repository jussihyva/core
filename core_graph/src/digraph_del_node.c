/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/digraph.h"

static t_bool	delete_inbound_edges(t_digraph_node *node)
{
	t_digraph_edge	*e_org;
	t_digraph_edge	*e_dst;
	t_size	i;
	t_size	j;

	i = 0;
	while (i < node->e_in.len)
	{
		e_org = parr_get(&node->e_in, i);
		j = 0;
		while (j < e_org->u->e_out.len)
		{
			e_dst = parr_get(&e_org->u->e_out, j);
			if (e_dst->u == e_org->v && e_dst->v == e_org->u)
				break ;
			j++;
		}
		if (e_org && e_dst)
		{
			parr_del(&node->e_in, i);
			parr_del(&e_org->u->e_out, j);
		}
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static t_bool	delete_outbound_edges(t_digraph_node *node)
{
	t_digraph_edge	*e_org;
	t_digraph_edge	*e_dst;
	t_size	i;
	t_size	j;

	i = 0;
	while (i < node->e_out.len)
	{
		e_org = parr_get(&node->e_out, i);
		j = 0;
		while (j < e_org->v->e_in.len)
		{
			e_dst = parr_get(&e_org->v->e_in, j);
			if (e_dst->u == e_org->v && e_dst->v == e_org->u)
				break ;
			j++;
		}
		if (e_org && e_dst)
		{
			parr_del(&node->e_out, i);
			parr_del(&e_org->v->e_in, j);
			free(e_org);
		}
		else
			return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	digraph_del_node(
		t_digraph *src,
		const char *name)
{
	t_digraph_node *node;

	node = digraph_find_node(src, name);
	if (!(delete_outbound_edges(node)))
		return (FALSE);
	if (!(delete_inbound_edges(node)))
		return (FALSE);
	map_del(&src->nodes, node->name);
	parr_free(&node->e_in);
	parr_free(&node->e_out);
	free((char *)node->name);
	free(node);
	src->ncount--;
	return (TRUE);
}
