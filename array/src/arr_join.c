
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

ssize_t	arr_join(t_arr *dst, t_arr *src)
{
	uint8_t	*mem_start;
	size_t	newsize;

	newsize = src->len + dst->len;
	if (dst->alloc_size < newsize)
		arr_grow(dst, dst->len + src->len);
	mem_start = dst->data;
	mem_start = &mem_start[dst->len * dst->elem_size];
	memcpy(mem_start, src->data, (newsize - dst->len) * dst->elem_size);
	dst->len = newsize;
	return(CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_JOIN
**
**	Join arrays by appending `src` to `dst`.
**
**  ----------------------------------------------------------------------------
*/
