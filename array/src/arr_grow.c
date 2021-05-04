/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Grow the allocated memory in a dynamic array.
 *
 * Mostly for internal use, but can be used to skip resizing steps.
 *
 * \param src Source array.
 * \param new_size New alloc_size for the array.
 *
 * \return New allocated size on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_grow(t_arr *arr, size_t new_size)
{
	t_arr	out;

	out = arr_new(new_size, arr->elem_size);
	if (arr_null(&out))
		return (CR_FAIL);
	arr_copy(&out, arr);
	arr_free(arr);
	*arr = out;
	return ((ssize_t)out.alloc_size);
}
