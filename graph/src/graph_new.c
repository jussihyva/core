/*******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

t_graph graph_new(char *name)
{
	t_graph	new_graph;

	new_graph.name = name;
	new_graph.nodes = arr_new(1, sizeof(t_graph_node));
	if (arr_null(&new_graph.nodes))
		return (CR_GRAPH_NULL);
	return (new_graph);
}
