/*******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

t_graph graph_new(void *attr)
{
	t_graph	new_graph;

	new_graph.data = map_new();
	new_graph.attr = attr;
	new_graph.next_id = 0;
	if (map_null(&new_graph.data))
		return (CR_GRAPH_NULL);
	return (new_graph);
}
