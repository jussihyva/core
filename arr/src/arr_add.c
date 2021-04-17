/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 14:15:07 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_add(t_arr *arr, void *data, size_t index)
{
	uint8_t	*mem_pos;
	uint8_t	*mem_tmp;

	if (arr_null(arr))
		return (ARR_FAIL);
	if (arr->count == arr->size)
	{
		if (!(arr_grow(arr, (arr->size + 1) * 2)))
			return (ARR_FAIL);
	}
	mem_pos = arr->data;
	mem_pos += index * arr->memsize;
	mem_tmp = arr->data;
	mem_tmp += (index + 1) * arr->memsize;
	mem_move(mem_tmp, mem_pos, arr->memsize * (arr->count - index));
	mem_cpy_safe(mem_pos, data, arr->memsize);
	arr->count++;
	return (ARR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD
**
**	Add a new member to any index in an array. If index exceeds member
**	count, new member is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
