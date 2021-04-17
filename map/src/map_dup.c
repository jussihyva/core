/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_dup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:35:03 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

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

int				map_dup(t_map *dst, t_map *src, size_t size)
{
	void		*member;
	size_t		i;

	i = 0;
	if (map_null(src) || map_null(dst))
		return (MAP_FAIL);
	while (i < src->len)
	{
		member = internal_memcpy(member, map_get(src, i), size);
		if (!(map_add_last(dst, member)))
			return (MAP_FAIL);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_DUP
**
**	Duplicate contents from `src` to `dst`. This method assumes that all
**	members in the array are of equal size and that size is passed in bytes in
**	the parameter `size`.
**
**  ----------------------------------------------------------------------------
*/
