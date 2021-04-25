/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 00:48:45 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_copy(t_arr *dst, t_arr *src)
{
	uint8_t	*mem_start;

	if (arr_null(src))
		return (CR_FAIL);
	if (dst->alloc_size < src->len)
		arr_grow(dst, src->alloc_size);
	mem_start = dst->data;
	dst->data = memcpy(mem_start, src->data, src->len * src->elem_size);
	dst->len = src->len;
	return (CR_SUCCESS);
}

/*
 *  ----------------------------------------------------------------------------
 *
 * Copy elements from `src` to `dst`.
 *
 *  ----------------------------------------------------------------------------
 */
