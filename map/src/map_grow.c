/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_grow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:17:34 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_grow(t_map *arr, size_t new_size)
{
	t_map		out;
	int			error;

	out = map_new(new_size);
	if (map_null(&out))
		return (MAP_FAIL);
	out.len = arr->len;
	if (!(error = map_copy(&out, arr)))
		return (MAP_FAIL);
	map_free(arr);
	*arr = out;
	return (out.size);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_GROW
**
**	Increase the size of the array.
**
**  ----------------------------------------------------------------------------
*/
