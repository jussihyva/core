/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Join arrays.
 *
 * Appends elements from src to dst. Arrays need to have identical element
 * sizes or function returns an error. However the function can't know if the
 * elements not are the same if they have the same size.
 *
 * \param dst Destination array.
 * \param src Source array.
 *
 * \return 1 on success and 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_join(t_array *dst, t_array *src)
{
	uint8_t	*mem_start;
	size_t	newsize;

	if (dst->elem_size != src->elem_size)
		return (CR_FAIL);
	newsize = src->len + dst->len;
	if (dst->alloc_size < newsize)
		arr_grow(dst, dst->len + src->len);
	mem_start = dst->data;
	mem_start = &mem_start[dst->len * dst->elem_size];
	memcpy(mem_start, src->data, (newsize - dst->len) * dst->elem_size);
	dst->len = newsize;
	return(CR_SUCCESS);
}
