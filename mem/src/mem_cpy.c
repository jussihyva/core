/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/15 19:27:21 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

static void			copy_words(const void *dst, const void *src, size_t words)
{
	const size_t	*src64;
	size_t			*dst64;
	size_t			pages;
	size_t			offset;

	pages = words / 4;
	offset = words - pages * 4;
	src64 = (const size_t *)src;
	dst64 = (size_t *)dst;
	while (pages--)
	{
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
		*dst64++ = *src64++;
	}
	while (offset--)
		*dst64++ = *src64++;
}

void				*mem_cpy(void *dst, const void *src, const size_t size)
{
	const char		*src8;
	char			*dst8;
	size_t			offset;
	size_t			words;
	size_t			aligned_size;

	words = size / 8;
	aligned_size = words * 8;
	offset = size - aligned_size;
	copy_words(dst, src, words);
	if (offset)
	{
		src8 = (const char *)src;
		src8 = &src8[aligned_size];
		dst8 = (char *)dst;
		dst8 = &dst8[aligned_size];
		while (offset--)
			*dst8++ = *src8++;
	}
	return (dst);
}

/*
**  ----------------------------------------------------------------------------
**
**	MEM_CPY
**
**	Void memory copy; copies `n` bytes from memory area `src` to memory area
**	`dst`. If `dst` and `src` overlap, behavior is undefined. Applications in
**	which `dst` and `src` might overlap should use `mem_move` instead.
**
**  ----------------------------------------------------------------------------
*/
