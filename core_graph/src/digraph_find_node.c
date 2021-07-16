/******************************************************************************
 * \authors Julius Koskela
 * \brief Find node from a graph by id.
 * \param g Source graph.
 * \param id Id to be matched.
 * \return Pointer to the node if a node is found, NULL otherwise.
 *****************************************************************************/
#include "../inc/digraph.h"

t_digraph_node	*digraph_find_node(t_digraph *src, const char *name)
{
	t_digraph_node	*tmp;

	if (!name)
		return (NULL);
	tmp = map_get(&src->nodes, name);
	return (tmp);
}
