/*******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

t_graph graph_new(void)
{
	t_graph	new_graph;

	new_graph = map_new();
	if (map_null(&new_graph))
		return (CR_GRAPH_NULL);
	return (new_graph);
}
