/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Take an element from specified index in a dynamic array.
 *
 * Take is a combination of get and del. A pointer to an allocated memory dst
 * sufficient to hold the results has to be passed as a parameter.
 *
 * \param dst Destination memory.
 * \param src source array.
 *
 * \return Pointer to dst.
 *
 *****************************************************************************/

#include "../inc/arr.h"
#include "../../inc/core.h"

void	*arr_take(void *dst, t_array *src, size_t index)
{
	void	*tmp;

	if (index >= src->len)
		return (NULL);
	tmp = arr_get(src, index);
	dst = memcpy(dst, tmp, src->elem_size);
	if (!(arr_del(src, index)))
		return (NULL);
	return (dst);
}
