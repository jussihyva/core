/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_add_last(t_arr *arr, void *data)
{
	uint8_t	*mem_pos;

	if (arr_null(arr))
		return (CR_FAIL);
	if (arr->count == arr->size)
	{
		if (!(arr_grow(arr, (arr->size + 1) * 2)))
			return (CR_FAIL);
	}
	mem_pos = arr->data;
	mem_pos += arr->count * arr->memsize;
	mem_pos = mem_cpy(mem_pos, data, arr->memsize);
	arr->count++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_ADD_LAST
**
**	Add a new member to the end of a dynamic string. If the string is not
**	sufficiently big a new memory area double the size of the previous one
**	is allocated. One extra member is added to the allocation for the case
**	that the string has size 0.
**
**  ----------------------------------------------------------------------------
*/
