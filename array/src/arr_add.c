/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Add element to a specific index in a dynamic dstay.
 *
 * Add an element to an index passed as an argument. If index is out of bounds
 * returns 0.
 *
 * \param dst Destination array.
 * \param elem Element to be added.
 * \param index Index where element will be added.
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../../inc/core.h"

t_ssize	arr_add(t_array *dst, void *elem, t_size index)
{
	t_byte	*mem_pos;
	t_byte	*mem_tmp;

	if (index >= dst->len)
		return (CR_FAIL);
	if (dst->len == dst->mem.size / dst->elem_size)
		mem_realloc(&dst->mem, dst->mem.size * 2);
	mem_pos = dst->mem.data;
	mem_pos += index * dst->elem_size;
	mem_tmp = dst->mem.data;
	mem_tmp += (index + 1) * dst->elem_size;
	mmove(mem_tmp, mem_pos, dst->elem_size * (dst->len - index));
	mcpy(mem_pos, elem, dst->elem_size);
	dst->len++;
	return (CR_SUCCESS);
}
