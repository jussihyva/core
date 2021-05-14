/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/14 18:43:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"
#include "../../inc/core.h"

ssize_t	parr_copy(t_parray *dst, t_parray *src)
{
	size_t	i;

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
