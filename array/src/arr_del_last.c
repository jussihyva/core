/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Delete last element in a dynamic array.
 *
 * If the element has pointers to allocated memory, those have to be handled
 * by the user.
 *
 * \param src Source array.
 * \return 1 on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"
#include "../../inc/core.h"

ssize_t	arr_del_last(t_array *arr)
{
	if (!(arr_del(arr, arr->len - 1)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}
