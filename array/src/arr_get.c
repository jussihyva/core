/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Get a pointer to an element at a spesific index.
 *
 * Does not copy the element, pointer points directly to the memory in the
 * array so be careful. Checks for out of bounds index.
 *
 * \param src Source array.
 *
 * \return Pointer to an element or NULL if no element is found.
 *
 *****************************************************************************/

#include "../../inc/core.h"

void	*arr_get(t_array *src, size_t index)
{
	uint8_t	*mem_pos;

	if (index >= src->len || src->len == 0)
		return (NULL);
	mem_pos = src->mem.data;
	mem_pos += index * src->elem_size;
	return (mem_pos);
}
