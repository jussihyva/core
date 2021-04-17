/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_split.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:30:14 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_split(t_map *dst, t_map *src)
{
	size_t		o_size;
	size_t		i;

	if (map_null(dst) || map_null(src))
		return (MAP_FAIL);
	o_size = src->len;
	i = 0;
	while (i <= o_size / 2)
	{
		if (!(map_add_last(dst, map_take_last(src))))
			return (MAP_FAIL);
		i++;
	}
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_SPLIT
**
**	Split array `src` by putting half of it's members into `src`.
**
**  ----------------------------------------------------------------------------
*/
