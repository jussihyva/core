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

#include "../inc/arr.h"
#include "../../inc/core.h"

ssize_t	arr_search(t_array *src, t_array *key)
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
