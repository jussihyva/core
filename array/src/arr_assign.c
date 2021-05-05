/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Assign raw data to an array.
 *
 * Assign raw data to an array. It is assumed that the elements in the source
 * data are of size dst.elem_size which has been defined when creating the
 * array.
 *
 * \param dst Destination array.
 * \param data Raw data to be added.
 * \param len Length of data at stride dst.elem_size.
 * \return 1 on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_assign(t_arr *dst, void *data, size_t len)
{
	if (dst->alloc_size > 0)
		return (CR_FAIL);
	free(dst->data);
	dst->data = data;
	dst->len = len;
	return (CR_SUCCESS);
}
