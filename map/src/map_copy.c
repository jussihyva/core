/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_copy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/11 01:00:08 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_copy(t_map *dst, t_map *src)
{
	size_t		i;

	i = 0;
	if (map_null(src) || map_null(dst))
		return (MAP_FAIL);
	while (i < src->len)
	{
		if (i == dst->size)
			return (i);
		dst->data[i] = src->data[i];
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_COPY
**
**	Copy as many members from `dst` as `src` can hold without reallocations.
**	Returns the amount of members copied.
**
**  ----------------------------------------------------------------------------
*/
