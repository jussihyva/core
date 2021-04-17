/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_join.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:29:34 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_join(t_map *dst, size_t len, ...)
{
	va_list		ap;
	t_map		*tmp;
	size_t		i;

	va_start(ap, len);
	if (map_null(dst))
		return (MAP_FAIL);
	while (len--)
	{
		tmp = va_arg(ap, t_map *);
		if (map_null(tmp))
			return (MAP_FAIL);
		i = 0;
		while (i < tmp->len && tmp->data[i])
		{
			if (!(map_add_last(dst, tmp->data[i])))
				return (MAP_FAIL);
			i++;
		}
	}
	va_end(ap);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_JOIN
**
**	Join `len` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
