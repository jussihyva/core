/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	map_null_node(t_map_node *n)
{
	if (mcmp(n, &CR_MAP_NULL_NODE, sizeof(t_map_node)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}
