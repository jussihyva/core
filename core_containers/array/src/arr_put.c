/******************************************************************************
 * \authors Julius Koskela
 * \brief Unfinished!
 * \param
 * \return
 *****************************************************************************/

#include "../../../inc/core.h"

t_ssize	arr_put(t_array *dst, void *src, t_size size)
{
	t_size	i;
	t_byte	*raw;

	if (!src)
		return (CR_FAIL);
	raw = src;
	i = 0;
	while (i < size)
	{
		arr_add_last(dst, raw);
		raw += dst->elem_size;
		i++;
	}
	return ((t_ssize)dst->len);
}
