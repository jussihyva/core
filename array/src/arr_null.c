/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Checks if the array is a null array.
 *
 * \param src The source array.
 *
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../inc/arr.h"
#include "../../inc/core.h"

ssize_t	arr_null(t_array *src)
{
	if (memcmp(src, &CR_ARR_NULL, sizeof(t_array)) == 0)
		return (CR_SUCCESS);
	return (CR_FAIL);
}
