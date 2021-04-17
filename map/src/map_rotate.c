/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:33:05 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int			map_rotate(t_map *arr, ssize_t steps)
{
	void	*tmp;
	ssize_t	i;

	if (map_null(arr))
		return (MAP_FAIL);
	i = 0;
	if (arr->len < 2 || steps == 0)
		return (0);
	if (steps > 0)
	{
		while (i < steps)
		{
			tmp = map_take_first(arr);
			map_add_last(arr, tmp);
			i++;
		}
	}
	else if (steps < 0)
	{
		steps = steps * -1;
		while (i < steps)
		{
			tmp = map_take_last(arr);
			map_add_first(arr, tmp);
			i++;
		}
	}
	return (MAP_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_ROTATE
**
**	Rotate array. Last element becomes the first element.
**
**  ----------------------------------------------------------------------------
*/

