/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

void		*arr_get(t_arr *src, size_t index)
{
	uint8_t	*mem_pos;

	if (index > src->count || src->count == 0)
		return (CR_FAIL);
	mem_pos = src->data;
	mem_pos += index * src->memsize;
	return (mem_pos);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_GET
**
**	Pull a member from a dynamic array at `index`.
**
**  ----------------------------------------------------------------------------
*/
