/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../inc/graph.h"

ssize_t	graph_cmp_nodes(const void *n1, const void *n2)
{
	t_graph_node	*n1c;
	t_graph_node	*n2c;

	n1c = (t_graph_node *)n1;
	n2c = (t_graph_node *)n2;
	if (n1c->id == n2c->id)
		return (1);
	return (0);
}
