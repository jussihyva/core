/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_take_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:28:13 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void			*map_take_last(t_map *arr)
{
	void		*out;

	if (map_null(arr))
		return (NULL);
	out = map_get_last(arr);
	if (!(map_del_last(arr)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_TAKE_LAST
**
**	Take the last member from an array. Contrary to get, take also
**	removes the member from the array.
**
**  ----------------------------------------------------------------------------
*/
