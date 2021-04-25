/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 00:48:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_del(t_arr *arr, size_t index)
{
	uint8_t	*mem_start;
	uint8_t	*mem_end;

	if (index > arr->len)
		return (CR_FAIL);
	if (index == arr->len -1)
	{
		arr->len--;
		return (CR_SUCCESS);
	}
	mem_start = arr->data;
	mem_start += index * arr->elem_size;
	mem_end = arr->data;
	mem_end += (index + 1) * arr->elem_size;
	memcpy(mem_start, mem_end, arr->elem_size * (arr->len - index));
	arr->len--;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_DEL
**
**	Delete a member at `index` from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
