///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Free node set.
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

void	digraph_free_node_set(t_digraph_node_set *src)
{
	parr_free(&src->nodes);
}
