/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_grow.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 00:14:30 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_grow(t_arr *arr, size_t new_size)
{
	t_arr	out;

	out = arr_new(arr->elem_size);
	if (!(arr_alloc(&out, new_size)))
		return (CR_FAIL);
	arr_copy(&out, arr);
	arr_free(arr);
	*arr = out;
	return ((ssize_t)out.alloc_size);
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
