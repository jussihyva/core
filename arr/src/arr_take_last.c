/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_take_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

void			*arr_take_last(void *dst, t_arr *src)
{
	if (arr_null(src))
		return (NULL);
	dst = arr_take(dst, src, src->count - 1);
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_TAKE_LAST
**
**	Take the last member from the array. Contrary to get, take also
**	removes the member from the array. For this same reason it takes as the
**	first argument a pointer to an allocated memory sufficient to hold
**	src->memsize amount of data.
**
**  ----------------------------------------------------------------------------
*/
