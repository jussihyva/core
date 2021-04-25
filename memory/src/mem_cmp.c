/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:25 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/20 18:23:04 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

int		mem_cmp(const void *src, const void *cmp, size_t size)
{

	const uint8_t	*src8;
	const uint8_t	*dst8;

	src8 = (const uint8_t *)src;
	dst8 = (const uint8_t *)cmp;
	while (size--)
	{
		if (*src8 != *dst8)
			return (*src8 - *dst8);
		dst8++;
		src8++;
	}
	return (0);
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
