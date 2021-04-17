/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 18:16:22 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_join(t_arr *dst, size_t count, ...)
{
	va_list	ap;
	t_arr	*tmp;
	size_t	i;

	va_start(ap, count);
	if (arr_null(dst))
		return (ARR_FAIL);
	while (count--)
	{
		tmp = va_arg(ap, t_arr *);
		if (arr_null(tmp))
			return (ARR_FAIL);
		i = 0;
		while (i < tmp->count)
		{
			if (!(arr_add_last(dst, arr_get(tmp, i))))
				return (ARR_FAIL);
			i++;
		}
	}
	va_end(ap);
	return ((ssize_t)dst->count);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_JOIN
**
**	Join `count` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
