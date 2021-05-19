/******************************************************************************
 *
 * \authors Julius Koskela
 *
 * \brief Search array key from src.
 *
 * Searches for data in src that matches the whole data in key and returns the
 * index of the first matching element.
 *
 * \param src Source array.
 * \param key Array data to be matched.
 *
 * \return Index of the fisrt matching element on success, -1 on failure.
 *
 *****************************************************************************/

#include "../../inc/core.h"

t_ssize	arr_search(t_array *src, t_array *key)
{
	t_byte	*mem_key;
	t_byte	*mem_src;
	t_size	i;

	if (src->elem_size != key->elem_size)
		return (CR_FAIL);
	mem_src = (t_byte *)src->mem.data;
	mem_key = (t_byte *)key->mem.data;
	i = 0;
	while (i < src->len)
	{
		if (mcmp(&mem_src[key->elem_size * i],
				mem_key, key->len * key->elem_size) == 0)
			return ((t_ssize)i);
		i++;
	}
	return (CR_EMPTY);
}
