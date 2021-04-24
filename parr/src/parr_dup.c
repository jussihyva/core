/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:35:03 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

static void		*internal_memcpy(void *dst, const void *src, uint64_t n)
{
	const char	*s;
	char		*d;

	if (src == NULL)
		return (NULL);
	dst = malloc(n);
	s = (const char *)src;
	d = (char *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int				parr_dup(t_parr *dst, t_parr *src, size_t size)
{
	void		*member;
	size_t		i;

	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		member = internal_memcpy(member, parr_get(src, i), size);
		if (!(parr_add_last(dst, member)))
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
