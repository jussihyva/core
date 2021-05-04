/*******************************************************************************
 * \brief Check if graph g is a null graph for error checking.
 * \return 1 on success 0 on failure.
 ******************************************************************************/

#include "../inc/graph.h"

ssize_t graph_null(t_graph *g)
{
	if (memcmp(g, &CR_GRAPH_NULL, sizeof(t_graph)) == 0)
		return (CR_SUCCESS);
	return (CR_FAIL);
}
