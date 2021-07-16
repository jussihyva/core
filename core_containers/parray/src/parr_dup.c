/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:17:47 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_dup(
		t_parray *dst,
		t_parray *src,
		t_size size)
{
	void	*elem;
	t_ret	ret;
	t_size	i;

	elem = NULL;
	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_ERROR_INPUT);
	while (i < src->len)
	{
		mcpy_safe(elem, parr_get(src, i), size);
		ret = parr_add_last(dst, elem);
		if (ret < 0)
			return (ret);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_DUP
**
**	Duplicate contents from `src` to `dst`. This method assumes that all
**	elements in the array are of equal size and that size is passed in bytes in
**	the parameter `size`.
**
**  ----------------------------------------------------------------------------
*/
