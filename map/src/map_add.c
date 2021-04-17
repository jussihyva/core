/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:16:25 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_add(t_map *arr, void *data, size_t index)
{
	t_map		newarr;
	void		*tmp;
	size_t		i;

	if (index > arr->len)
		return (MAP_FAIL);
	newarr = map_new(arr->size);
	if (map_null(&newarr))
		return (MAP_FAIL);
	i = 0;
	while (i < index)
	{
		tmp = map_take_first(arr);
		if (!(map_add_last(&newarr, tmp)))
			return (MAP_FAIL);
		i++;
	}
	map_add_last(&newarr, data);
	map_join(&newarr, 1, arr);
	map_free(arr);
	*arr = newarr;
	return (MAP_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_ADD
**
**	Add a new member to any index in an array. If index exceeds member
**	len, new member is added to the end of the array.
**
**  ----------------------------------------------------------------------------
*/
