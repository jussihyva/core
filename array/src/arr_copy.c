/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/20 19:35:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_copy(t_arr *dst, t_arr *src)
{
	uint8_t	*mem_start;

	if (arr_null(src) || arr_null(dst))
		return (CR_FAIL);
	if (dst->size < src->len)
		arr_grow(dst, src->size);
	mem_start = dst->data;
	dst->data = mem_cpy(mem_start, src->data, src->len * src->elem_size);
	dst->len = src->len;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_COPY
**
**	Copy as many members from `dst` as `src` can hold without reallocations.
**	Returns the amount of members copied.
**
**  ----------------------------------------------------------------------------
*/
