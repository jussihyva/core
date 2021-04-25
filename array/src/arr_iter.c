/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 16:57:24 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_iter(t_arr *arr,
		ssize_t (*f)(void *, size_t))
{
	size_t	i;
	void	*tmp;

	if (arr_null(arr))
		return (CR_FAIL);
	i = 0;
	while (i < arr->len)
	{
		tmp = arr_get(arr, i);
		if ((f(tmp, i)) == CR_STOP)
			return ((ssize_t)i);
		i++;
	}
	return ((ssize_t)i);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ITER
**
**	Iterate a dynamic array and execute a function passed by f on all
**	members.
**
**  ----------------------------------------------------------------------------
*/
