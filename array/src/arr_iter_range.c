/*******************************************************************************
 * \authors Julius Koskela
 * \brief
 * \param
 * \return
 ******************************************************************************/

#include "../inc/arr.h"

ssize_t	arr_iter_range(t_arr *arr, size_t start, size_t end,
		ssize_t (*fptr)(void *, size_t))
{
	size_t	i;
	void	*tmp;

	i = start;
	if (arr_null(arr)
	|| start > arr->len
	|| end > arr->len
	|| start < end)
		return (CR_FAIL);
	while (i < end)
	{
		tmp = arr_get(arr, i);
		if (!(fptr(tmp, i)))
			return ((ssize_t)i);
		i++;
	}
	return ((ssize_t)i);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ITER_RANGE
**
**	Iterate range between start and end and apply `fptr` to each member.
**
**  ----------------------------------------------------------------------------
*/
