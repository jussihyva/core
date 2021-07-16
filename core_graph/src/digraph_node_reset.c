/******************************************************************************
 * \brief Resets node as valid.
 *****************************************************************************/

#include "../inc/digraph.h"

t_ssize	digraph_node_reset(void *data, t_size i)
{
	t_digraph_node	*n;

	n = data;
	n->valid = TRUE;
	return ((t_ssize)i);
}
