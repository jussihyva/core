/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/13 11:14:59 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_parse(t_map *dst, t_map *src, int (*f)(t_map *, void *))
{
	size_t		i;
	void		*data;

	i = 0;
	if (map_null(src) || map_null(dst))
		return (MAP_FAIL);
	while (i < src->len)
	{
		data = map_get(src, i);
		if (!(f(dst, data)))
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_PARSE
**
**	Iterate array `src` so that for each member a parse function is executed
**	The parse function is user-defined and parses each member so that rersults
**	are added in `dst`.
**
**  ----------------------------------------------------------------------------
*/
