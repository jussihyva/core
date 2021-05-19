/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../inc/core.h"

t_ssize	map_null(t_map *src)
{
	if (memcmp(src, &CR_MAP_NULL, sizeof(t_map)) == 0)
		return (1);
	return (0);
}
