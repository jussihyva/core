/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_assign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:21:06 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_assign(t_map *arr, void **src, size_t size)
{
	size_t		i;

	i = 0;
	if (map_null(arr) || !src || size < 1)
		return (MAP_FAIL);
	while (i < size)
	{
		if (!(map_add_last(arr, src[i])))
			return (MAP_FAIL);
		i++;
	}
	return (arr->size);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_ASSIGN
**
**	Assign an array of pointer of known size to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
