/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:53 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/16 18:54:02 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

void					*mem_move(void *dst, const void *src, size_t n)
{
	const unsigned char	*src8;
	unsigned char		*dst8;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst8 = dst;
	src8 = src;
	if (dst8 < src8)
		mem_cpy(dst8, src8, n);
	else
		while (n--)
			*(unsigned char *)(dst8 + n) = *(unsigned char *)(src8 + n);
	return (dst8);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_MOVE
**
**	Void memory move; copies `len` bytes from string `src` to string `dst`.
**	The two strings may overlap; the copy is always done in a non-destructive
**	manner.
**
**  ----------------------------------------------------------------------------
*/
