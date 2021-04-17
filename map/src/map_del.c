/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:22:49 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_del(t_map *arr, size_t index)
{
	size_t		i;

	if (map_null(arr))
		return (MAP_FAIL);
	if (index > arr->len)
		return (MAP_FAIL);
	i = index;
	while (i < arr->len)
	{
		arr->data[i] = arr->data[i + 1];
		i++;
	}
	arr->len--;
	return (MAP_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_DEL
**
**	Delete a member at `index` from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
