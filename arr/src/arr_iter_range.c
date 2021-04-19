/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_iter_range.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_iter_range(t_arr *arr, size_t start, size_t end,
			ssize_t (*fptr)(void *, size_t))
{
	size_t	i;
	void	*tmp;

	i = start;
	if (arr_null(arr))
	{
		perror("arr_iter_range: EMPTY ARRAY\n");
		return (CR_FAIL);
	}
	if (start > arr->count || end > arr->count || start < end)
	{
		perror("arr_iter_range: OUT OF BOUNDS\n");
		return (CR_FAIL);
	}
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
**	CR_ITER_RANGE
**
**	Iterate range between start and end and apply `fptr` to each member.
**
**  ----------------------------------------------------------------------------
*/
