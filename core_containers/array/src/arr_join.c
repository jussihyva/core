/******************************************************************************
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
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	arr_join(t_array *dst, t_array *src)
{
	t_byte	*mem_start;
	t_size	newsize;

	if (dst->elem_size != src->elem_size)
		return (CR_FAIL);
	newsize = src->len + dst->len;
	if (dst->len == dst->mem.size / dst->elem_size)
		mem_realloc(&dst->mem, dst->mem.size * 2);
	mem_start = dst->mem.data;
	mem_start = &mem_start[dst->len * dst->elem_size];
	mcpy(mem_start, src->mem.data, (newsize - dst->len) * dst->elem_size);
	dst->len = newsize;
	return (CR_SUCCESS);
}
