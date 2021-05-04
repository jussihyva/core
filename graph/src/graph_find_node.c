/*******************************************************************************
 * \authors Julius Koskela
 * \brief Find node from a graph by id.
 * \param g Source graph.
 * \param id Id to be matched.
 * \return Pointer to the node if a node is found, NULL otherwise.
 ******************************************************************************/
#include "../inc/graph.h"

t_graph_node	*graph_find_node(t_graph *g, const ssize_t id)
{
	t_graph_node	*tmp;
	size_t	i;

	i = 0;
	while (i < g->nodes.len)
	{
		tmp = arr_get(&g->nodes, i);
		if (tmp->id == id)
			return (tmp);
		i++;
	}
	return (NULL);
}
