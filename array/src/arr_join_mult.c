/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_join_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 23:40:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_join_mult(t_arr *dst, size_t len, ...)
{
	va_list	ap;
	t_arr	*tmp;

	va_start(ap, len);
	while (len--)
	{
		tmp = va_arg(ap, t_arr *);
		if (arr_null(tmp))
			return (CR_FAIL);
		if (!(arr_join(dst, tmp)))
			return (CR_FAIL);
	}
	va_end(ap);
	return ((ssize_t)dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_JOIN_MULT
**
**	Join `len` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
