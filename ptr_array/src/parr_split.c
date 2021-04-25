/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:30:14 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

int				parr_split(t_parr *dst, t_parr *src)
{
	size_t		o_size;
	size_t		i;

	if (parr_null(dst) || parr_null(src))
		return (CR_FAIL);
	o_size = src->len;
	i = 0;
	while (i <= o_size / 2)
	{
		if (!(parr_add_last(dst, parr_take_last(src))))
			return (CR_FAIL);
		i++;
	}
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_SPLIT
**
**	Split array `src` by putting half of it's members into `src`.
**
**  ----------------------------------------------------------------------------
*/
