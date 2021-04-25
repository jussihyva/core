/*
 * ----------------------------------------------------------------------------
 *
 * Assign data to an array. This data will not be copied, rather the array
 * will refer to the data and manipulate it directly. If the array is grown
 * it will automatically allocate new memory for the data and copy it over.
 * User should still free the array object even though data might not be
 * allocated.
 *
 * ----------------------------------------------------------------------------
 */

#include "../inc/arr.h"

ssize_t	arr_assign(t_arr *dst, void *data, size_t len)
{
	if (dst->alloc_size > 0)
		return (CR_FAIL);
	dst->data = data;
	dst->reserv_size = len;
	dst->len = len;
	return (CR_SUCCESS);
}
