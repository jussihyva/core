/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 14:13:46 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_grow(t_arr *arr, size_t new_size)
{
	t_arr	out;

	if (arr_null(arr))
		return (ARR_FAIL);
	out = arr_new(new_size, arr->memsize);
	out.count = arr->count;
	if (!(arr_copy(&out, arr)))
		return (ARR_FAIL);
	arr_free(arr);
	*arr = out;
	return ((ssize_t)out.size);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_GROW
**
**	Increase the size of the array.
**
**  ----------------------------------------------------------------------------
*/
