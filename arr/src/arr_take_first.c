/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_take_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 12:35:11 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

void			*arr_take_first(void *dst, t_arr *src)
{
	if (arr_null(src))
		return (NULL);
	dst = arr_take(dst, src, 0);
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_TAKE_FIRST
**
**	Take the first member from the array. Contrary to get, take also
**	removes the member from the array. For this same reason it takes as the
**	first argument a pointer to an allocated memory sufficient to hold
**	src->memsize amount of data.
**
**  ----------------------------------------------------------------------------
*/
