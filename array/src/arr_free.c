/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Free an array passed as an argument.
 *
 * \param src Pointer to an array to be freed.
 *
 * \return 1 on success.
 *
 *****************************************************************************/

#include "../../inc/core.h"

t_ssize	arr_free(t_array *src)
{
	core_free(&src->mem);
	*src = CR_ARR_NULL;
	return (CR_SUCCESS);
}
