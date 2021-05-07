/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/07 23:08:20 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

static inline int
cmp_small(uint8_t *restrict dst, const uint8_t *restrict src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (dst[i] != src[i])
			return (-1);
		i++;
	}
	return (0);
}

static inline int
cmp512(uint64_t *restrict dst, const uint64_t *restrict src, size_t n)
{
	size_t chunks;
	size_t offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
		if (*dst++ != *src++)
			return (-1);
	}
	while (offset--)
		if (*dst++ != *src++)
			return (-1);
	return (0);
}

int
mem_cmp(const void *dst, const void *src, size_t n)
{
	uint8_t			*dst8;
	const uint8_t	*src8;
	size_t			qwords;
	size_t			aligned_size;

	dst8 = (uint8_t*)dst;
	src8 = (const uint8_t*)src;
	qwords = n >> 3;
	if (n > 8)
	{
		if ((cmp512((uint64_t*)dst, (const uint64_t*)src, qwords)) == -1)
			return (-1);
	}
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	return (cmp_small(dst8, src8, n));
}

/*int		mem_cmp(const void *src, const void *cmp, size_t size)*/
/*{*/

	/*const uint8_t	*src8;*/
	/*const uint8_t	*dst8;*/

	/*src8 = (const uint8_t *)src;*/
	/*dst8 = (const uint8_t *)cmp;*/
	/*while (size--)*/
	/*{*/
		/*if (*src8 != *dst8)*/
			/*return (*src8 - *dst8);*/
		/*dst8++;*/
		/*src8++;*/
	/*}*/
	/*return (0);*/
/*}*/

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
