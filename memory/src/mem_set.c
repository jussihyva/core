/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:58 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/19 21:00:01 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

static void		copy_words(uint64_t *dst, const int c, size_t words)
{
	uint64_t	pages;
	uint64_t	offset;

	pages = words / 4;
	offset = words - pages * 4;
	while (pages--)
	{
		*dst++ = c;
		*dst++ = c;
		*dst++ = c;
		*dst++ = c;
	}
	while (offset--)
		*dst++ = c;
}

void			*mem_set(void *dst, int c, size_t size)
{
	uint8_t		*dst8;
	size_t		offset;
	size_t		words;
	size_t		aligned_size;

	if (!dst)
		return (NULL);
	words = size / 8;
	aligned_size = words * 8;
	offset = size - aligned_size;
	copy_words(dst, c, words);
	if (offset)
	{
		dst8 = (uint8_t *)dst;
		dst8 = &dst8[aligned_size];
		while (offset--)
			*dst8++ = c;
	}
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	mem_set
**
**	Sets `size` bytes of memory pointed to by `dst` with value `c`.
**
**  ----------------------------------------------------------------------------
*/
