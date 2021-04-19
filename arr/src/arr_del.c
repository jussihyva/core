/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_del(t_arr *arr, size_t index)
{
	uint8_t	*mem_start;
	uint8_t	*mem_end;

	if (arr_null(arr))
		return (CR_FAIL);
	if (index > arr->count)
		return (CR_FAIL);
	mem_start = arr->data;
	mem_start += index * arr->memsize;
	mem_end = arr->data;
	mem_end += (index + 1) * arr->memsize;
	mem_cpy_safe(mem_start, mem_end, arr->memsize * (arr->count - index));
	arr->count--;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_DEL
**
**	Delete a member at `index` from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
