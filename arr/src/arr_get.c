/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 14:54:23 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

void		*arr_get(t_arr *src, size_t index)
{
	uint8_t	*mem_pos;

	if (index > src->count || src->count == 0)
		return (ARR_FAIL);
	mem_pos = src->data;
	mem_pos += index * src->memsize;
	return (mem_pos);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_GET
**
**	Pull a member from a dynamic array at `index`.
**
**  ----------------------------------------------------------------------------
*/
