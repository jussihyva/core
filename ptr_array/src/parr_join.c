/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/13 21:29:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"
# include "../../inc/core.h"

ssize_t	parr_join(t_parray *dst, size_t len, ...)
{
	va_list		ap;
	t_parray	*tmp;
	size_t		i;

	va_start(ap, len);
	if (parr_null(dst))
		return (CR_FAIL);
	while (len--)
	{
		tmp = va_arg(ap, t_parray *);
		if (parr_null(tmp))
			return (CR_FAIL);
		i = 0;
		while (i < tmp->len && tmp->data[i])
		{
			if (!(parr_add_last(dst, tmp->data[i])))
				return (CR_FAIL);
			i++;
		}
	}
	va_end(ap);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_JOIN
**
**	Join `len` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
