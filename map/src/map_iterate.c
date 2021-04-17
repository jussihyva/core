/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/13 11:24:56 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_iterate(t_map *arr, int (*f)(void **, size_t))
{
	size_t		i;
	int			ret;

	if (map_null(arr))
		return (MAP_FAIL);
	i = 0;
	while (i < arr->len)
	{
		if ((ret = f(&arr->data[i], i)) == MAP_STOP)
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_ITERATE
**
**	Iterate a dynamic array and execute a function passed by f on all
**	members.
**
**  ----------------------------------------------------------------------------
*/
