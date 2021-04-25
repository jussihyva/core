/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_iter_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 16:56:52 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
