/*
 *  ----------------------------------------------------------------------------
 *
 *	Take a member from the array. Contrary to `arr_get`, take also
 *	removes the member from the array. Takes as the
 *	first argument a pointer to an allocated memory sufficient to hold
 *	`src->elem_size` amount of data.
 *
 *  ----------------------------------------------------------------------------
 */

#include "../inc/arr.h"

void	*arr_take(void *dst, t_arr *src, size_t index)
{
	void	*tmp;

	if (index > src->len)
		return (NULL);
	tmp = arr_get(src, index);
	dst = memcpy(dst, tmp, src->elem_size);
	if (!(arr_del(src, index)))
		return (NULL);
	return (dst);
}
