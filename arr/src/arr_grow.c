/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_grow(t_arr *arr, size_t new_size)
{
	t_arr	out;

	if (arr_null(arr))
		return (CR_FAIL);
	out = arr_new(new_size, arr->memsize);
	out.count = arr->count;
	if (!(arr_copy(&out, arr)))
		return (CR_FAIL);
	arr_free(arr);
	*arr = out;
	return ((ssize_t)out.size);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_GROW
**
**	Increase the size of the array.
**
**  ----------------------------------------------------------------------------
*/
