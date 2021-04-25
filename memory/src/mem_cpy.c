/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 22:31:49 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

static inline void
copy_small(uint8_t *restrict dst, const uint8_t *restrict src, size_t n)
{
	if (n >= 8)
	{
		*(uint64_t *restrict)dst = *(const uint64_t *restrict)src;
		return;
	}
	if (n >= 4)
	{
		*(uint32_t *restrict)dst = *(const uint32_t *restrict)src;
		dst += 4;
		src += 4;
	}
	if (n & 2)
	{
		*(uint16_t *restrict)dst = *(const uint16_t *restrict)src;
		dst += 2;
		src += 2;
	}
	if (n & 1)
		*dst = *src;
}

static inline void
copy512(uint64_t *restrict dst, const uint64_t *restrict src, size_t n)
{
	size_t chunks;
	size_t offset;

	chunks = n >> 3;
	offset = n - (chunks << 3);
	while (chunks--)
	{
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
		*dst++ = *src++;
	}
	while (offset--)
		*dst++ = *src++;
}

void
*mem_cpy(void *restrict dst, const void *restrict src, size_t n)
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
		copy512((uint64_t*)dst, (const uint64_t*)src, qwords);
		return (dst);
	}
	aligned_size = qwords << 3;
	n -= aligned_size;
	dst8 += aligned_size;
	src8 += aligned_size;
	copy_small(dst8, src8, n);
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
