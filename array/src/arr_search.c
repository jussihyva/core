#include "../inc/arr.h"

ssize_t	arr_search(t_arr *src, t_arr *key)
{
	uint8_t	*mem_key;
	uint8_t	*mem_src;
	size_t	i;

	if (src->elem_size != key->elem_size)
		return (CR_FAIL);
	mem_src = (uint8_t *)src->data;
	mem_key = (uint8_t *)key->data;
	i = 0;
	while (i < src->len)
	{
		if (mem_cmp(&mem_src[key->elem_size * i],
		mem_key, key->len * key->elem_size) == 0)
			return ((ssize_t)i);
		i++;
	}
	return (CR_EMPTY);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_SEARCH
**
**	Search from an array by passing a key and a selection function. In the
**	selection function user can put any logic and anything returned from
**	the selection function is put into the array `dst` passed as an argument.
**
**  ----------------------------------------------------------------------------
*/
