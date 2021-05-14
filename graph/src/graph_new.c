/******************************************************************************
 * \brief Create a new graph g
 * \return 1 on success 0 on failure.
 *****************************************************************************/

#include "../inc/graph.h"

t_graph	graph_new(void)
{
	return (map_new());
}
