/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Delete an element from a specific index.
 *
 * If the element has pointers to allocated memory, those have to be handled
 * by the user. Checks for out of bounds index.
 *
 * \param src Source array.
 * \param index Index of the element to be deleted.
 * \return 1 on success 0 on failure.
 *
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	arr_del(t_array *src, t_size index)
{
	t_byte	*mem_start;
	t_byte	*mem_end;

	if (index >= src->len)
		return (CR_FAIL);
	if (index == src->len -1)
	{
		src->len--;
		return (CR_SUCCESS);
	}
	mem_start = src->mem.data;
	mem_start += index * src->elem_size;
	mem_end = src->mem.data;
	mem_end += (index + 1) * src->elem_size;
	mmove(mem_start, mem_end, src->elem_size * (src->len - index));
	src->len--;
	return (CR_SUCCESS);
}
