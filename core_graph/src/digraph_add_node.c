///////////////////////////////////////////////////////////////////////////////
///
/// digraph_add_node.c
///
/// \authors Julius Koskela
///
/// \brief Add a node n to graph g.
///
/// New adjacency lists in and out are created for the node, after which the
/// node is added into the graph.
///
/// \param g Source graph.
/// \param name Name of the node to be added.
/// \return TRUE or FALSE.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

t_bool	digraph_add_node(
		t_digraph *dst,
		const char *name,
		t_attr_node *attr)
{
	t_digraph_node	*n;

	n = (t_digraph_node *)malloc(sizeof(t_digraph_node));
	if (!n)
		return (FALSE);
	n->name = s_dup(name);
	n->valid = TRUE;
	n->attr = attr;
	if (!map_add(&dst->nodes, n, n->name))
	{
		free(n);
		return (FALSE);
	}
	parr_new(&n->e_in,1);
	parr_new(&n->e_out, 1);
	dst->ncount++;
	return (TRUE);
}

///////////////////////////////////////////////////////////////////////////////
