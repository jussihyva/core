/******************************************************************************
 * \authors Julius Koskela
 * \brief Unfinished!
 * \param
 * \return
 *****************************************************************************/

#include "../../inc/core.h"

t_ssize	arr_put(t_array *arr, void *src, t_size size)
{
	t_size	i;
	t_byte	*mem;

	if (!src)
		return (CR_FAIL);
	mem = src;
	i = 0;
	while (i < size)
	{
		arr_add_last(arr, mem);
		mem += arr->elem_size;
		i++;
	}
	return ((t_ssize)arr->len);
}
