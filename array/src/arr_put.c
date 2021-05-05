/*******************************************************************************
 * \authors Julius Koskela
 * \brief Unfinished!
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_put(t_arr *arr, void *src, size_t size)
{
	size_t	i;
	uint8_t	*mem;

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
	return ((ssize_t)arr->len);
}
