/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_add_mult.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:20:48 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_add_mult(t_map *arr, size_t len, ...)
{
	va_list		ap;

	va_start(ap, len);
	while (len--)
	{
		if (!(map_add_last(arr, va_arg(ap, void *))))
			return (MAP_FAIL);
	}
	va_end(ap);
	return (arr->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_ADD_MULT
**
**	Add `len` members to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
