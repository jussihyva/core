/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_copy(t_arr *dst, t_arr *src)
{
	if (arr_null(src) || arr_null(dst))
		return (CR_FAIL);
	dst->data = mem_cpy(dst->data, src->data, src->count * src->memsize);
	dst->count = src->count;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_COPY
**
**	Copy as many members from `dst` as `src` can hold without reallocations.
**	Returns the amount of members copied.
**
**  ----------------------------------------------------------------------------
*/
