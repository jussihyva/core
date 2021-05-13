/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/13 21:29:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"
# include "../../inc/core.h"

ssize_t	parr_dup(t_parray *dst, t_parray *src, size_t size)
{
	void	*elem;
	size_t	i;

	elem = NULL;
	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		elem = mem_cpy_safe(elem, parr_get(src, i), size);
		if (!(parr_add_last(dst, elem)))
			return (CR_FAIL);
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
**	members in the array are of equal size and that size is passed in bytes in
**	the parameter `size`.
**
**  ----------------------------------------------------------------------------
*/
