/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 14:57:30 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_copy(t_arr *dst, t_arr *src)
{
	if (arr_null(src) || arr_null(dst))
		return (ARR_FAIL);
	dst->data = mem_cpy(dst->data, src->data, src->count * src->memsize);
	dst->count = src->count;
	return (ARR_SUCCESS);
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
