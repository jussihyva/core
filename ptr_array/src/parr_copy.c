/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/11 01:00:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

int				parr_copy(t_parr *dst, t_parr *src)
{
	size_t		i;

	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		if (i == dst->size)
			return (i);
		dst->data[i] = src->data[i];
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_COPY
**
**	Copy as many members from `dst` as `src` can hold without reallocations.
**	Returns the amount of members copied.
**
**  ----------------------------------------------------------------------------
*/
