/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:53 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:29:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*mem_move(void *dst, const void *src, t_size size)
{
	const t_byte	*src8;
	t_byte			*dst8;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst8 = dst;
	src8 = src;
	if (dst8 < src8)
		mem_cpy(dst8, src8, size);
	else
		while (size--)
			*(dst8 + size) = *(src8 + size);
	return (dst8);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_MOVE
**
**	Void memory move; copies `size` bytes from string `src` to string `dst`.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
**
**  ----------------------------------------------------------------------------
*/
