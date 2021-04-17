/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/16 01:02:00 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

static int			mem_cmp_words(const void *src, const void *cmp, size_t words)
{

	const size_t	*src64;
	const size_t	*dst64;

	src64 = (const size_t *)src;
	dst64 = (const size_t *)cmp;
    while (words-- && *dst64 == *src64)
	{
		dst64++;
		src64++;
	}
    return (*src64 - *dst64);
}

int					mem_cmp(const void *src, const void *cmp, const size_t size)
{

	const char		*src8;
	const char		*dst8;
	size_t			offset;
	size_t			words;
	int				ret;

	words = size / 8;
	offset = size - words * 8;
	if ((ret = mem_cmp_words(src, cmp, words)) > 0)
		return (ret);
	src8 = (const char *)src;
	src8 = &src8[words * 8];
	dst8 = (const char *)cmp;
	dst8 = &dst8[words * 8];
	while (offset-- && src8 == dst8)
	{
		dst8++;
		src8++;
	}
	return (*src8 - *dst8);
}
/*
**  ----------------------------------------------------------------------------
**
**	MEM_CMP
**
**	Void memory compare; compares byte string `s1` against byte string `s2`.
**	Both strings are assumed to be n bytes long.
**
**	The `mem_chr` function returns zero if the two strings are identical, oth-
**	erwise returns the difference between the first two differing bytes
**	(treated as unsigned char values, so that `\200' is greater than `\0',
**	for example). Zero-length strings are always identical.
**
**  ----------------------------------------------------------------------------
*/
