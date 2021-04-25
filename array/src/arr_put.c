/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 23:41:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ASSIGN
**
**	Assign an array of pointer of known size to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
