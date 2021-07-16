/******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 *****************************************************************************/

#include "../inc/digraph.h"

t_bool	digraph_new(t_digraph *new, t_attr_graph *attr)
{
	map_new(&new->nodes, 1, CR_MAP_LINEAR, map_hash_fast);
	if (new->nodes.node == NULL)
		return (FALSE);
	new->attr = attr;
	new->ncount = 0;
	new->ecount = 0;
	return (TRUE);
}
