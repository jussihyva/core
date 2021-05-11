/******************************************************************************
 *
 * \authors Satu Koskinen
 *
 * \brief
 *
 *****************************************************************************/

#include "../../inc/core.h"
#include "../inc/print_internal.h"

void	ft_strdel(char **as)
{
	free(*as);
	*as = NULL;
}
