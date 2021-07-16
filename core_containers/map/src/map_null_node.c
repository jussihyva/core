/******************************************************************************
 * \authors
 * \brief
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_bool	map_null_node(t_map_node *n)
{
	if (n->data == NULL && n->tombstone == FALSE)
		return (TRUE);
	return (FALSE);
}
