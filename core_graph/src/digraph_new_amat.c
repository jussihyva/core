///////////////////////////////////////////////////////////////////////////////
///
/// \authors Julius Koskela
/// \brief Print adjancency matrix
///
///////////////////////////////////////////////////////////////////////////////

#include "../inc/digraph.h"

t_bool	digraph_new_amat(t_digraph_amat *new, t_size size)
{
	digraph_new_node_set(&new->all);
	new->matrix = malloc(size * size * sizeof(t_bool));
	mzero(new->matrix, size * size * sizeof(t_bool));
	if (!new->matrix)
		return (FALSE);
	new->size = size;
	return (TRUE);
}
