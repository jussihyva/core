/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_take_first.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:28:42 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void			*map_take_first(t_map *arr)
{
	void		*out;

	if (map_null(arr))
		return (NULL);
	out = map_get_first(arr);
	if (!(map_del_first(arr)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_TAKE_FIRST
**
**	Take the first member from an array. Contrary to get, take also
**	removes the member from the array.
**
**  ----------------------------------------------------------------------------
*/
