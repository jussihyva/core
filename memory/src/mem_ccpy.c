/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_ccpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:38:37 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

void	*mem_ccpy(void *dst, const void *src, int c, size_t n)
{
	uint8_t	*dst8;
	uint8_t	*src8;

	dst8 = (uint8_t *)dst;
	src8 = (uint8_t *)src;
	while (n--)
	{
		*dst8 = *src8;
		if (*src8 == (uint8_t)c)
			return (dst8 + 1);
		dst8++;
		src8++;
	}
	return (NULL);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_CCPY
**
**	Void memory copy (c); copies bytes from string src to string dst.  If
**	the character c (as converted to an uint8_t) occurs in the string
**	src, the copy stops and a pointer to the byte after the copy of c in the
**	memory dst is returned.  Otherwise, n bytes are copied, and a NULL
**	pointer is returned.
**
**  ----------------------------------------------------------------------------
*/
