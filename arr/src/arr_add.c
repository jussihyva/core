/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_add(t_arr *arr, void *data, size_t index)
{
	uint8_t	*mem_pos;
	uint8_t	*mem_tmp;

	if (arr_null(arr))
		return (CR_FAIL);
	if (arr->count == arr->size)
	{
		if (!(arr_grow(arr, (arr->size + 1) * 2)))
			return (CR_FAIL);
	}
	mem_pos = arr->data;
	mem_pos += index * arr->memsize;
	mem_tmp = arr->data;
	mem_tmp += (index + 1) * arr->memsize;
	mem_move(mem_tmp, mem_pos, arr->memsize * (arr->count - index));
	mem_cpy_safe(mem_pos, data, arr->memsize);
	arr->count++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_ADD
**
**	Add a new member to any index in an array. If index exceeds member
**	count, new member is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
