/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/digraph.h"

static char	*grab_node(void *dst, void *src, const char *key)
{
	t_parray	*nodes;

	nodes = dst;
	parr_add_last(nodes, src);
	return ((char *)key);
}

t_bool	digraph_collect_nodes(
		t_digraph *src,
		t_digraph_node_set *dst)
{
	if (!(map_parse(&src->nodes, &dst->nodes, grab_node)))
		return (FALSE);
	return (TRUE);
}
