/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_take.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:26:13 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void			*map_take(t_map *arr, size_t index)
{
	void		*out;

	if (index > arr->len || map_null(arr))
		return (NULL);
	out = map_get(arr, index);
	if (!(map_del(arr, index)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_TAKE
**
**	Take a member from a dynamic array at `index`. Contrary to get, take also
**	removes the member from the array.
**
**  ----------------------------------------------------------------------------
*/
