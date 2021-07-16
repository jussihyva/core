/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:10:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_copy(t_parray *dst, t_parray *src)
{
	t_size	i;

	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_ERROR_INPUT);
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
**	Copy as many elements from `dst` as `src` can hold without reallocations.
**	Returns the amount of elements copied.
**
**  ----------------------------------------------------------------------------
*/
