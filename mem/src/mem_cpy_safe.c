/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy_safe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 01:31:35 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/15 20:37:22 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/mem.h"

void			*mem_cpy_safe(void *dst, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (src == NULL)
		return (NULL);
	s = (const char *)src;
	d = (char *)dst;
	while (n--)
		*d++ = *s++;
	return (dst);
}
