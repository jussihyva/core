/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:14:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_split(
		t_parray *dst,
		t_parray *src)
{
	t_size	o_size;
	t_ret	ret;
	t_size	i;

	if (parr_null(dst) || parr_null(src))
		return (CR_ERROR_INPUT);
	o_size = src->len;
	i = 0;
	while (i <= o_size / 2)
	{
		ret = parr_add_last(dst, parr_take_last(src));
		if (ret < 0)
			return (ret);
		i++;
	}
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_SPLIT
**
**	Split array `src` by putting half of it's elements into `src`.
**
**  ----------------------------------------------------------------------------
*/
