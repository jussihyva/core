/*******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Copy elements from src to dst.
 *
 * Checks that element sizes match between the arrays and copies from src to
 * dst. Overrides any data in dst.
 *
 * \param dst Destination array.
 * \param src Source array.
 * \return 1 on success 0 on failure.
 *
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_copy(t_arr *dst, t_arr *src)
{
	uint8_t	*mem_start;

	if (arr_null(src))
		return (CR_FAIL);
	if (dst->alloc_size < src->len)
		arr_grow(dst, src->alloc_size);
	mem_start = dst->data;
	dst->data = memcpy(mem_start, src->data, src->len * src->elem_size);
	dst->len = src->len;
	return (CR_SUCCESS);
}
