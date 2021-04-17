/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:19 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

static int		map_write_string(t_map *dst, t_map *src)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (i < src->len)
	{
		tmp = src->data[i];
		map_add_last(dst, s_dup(tmp));
		i++;
	}
	return (i);
}
int				map_write(t_map *dst, t_map *src, int (*f)(void **, void *))
{
	size_t		i;
	void		*tmp;

	i = 0;
	if (f == MAP_STRING)
		return (map_write_string(dst, src));
	while (i < src->len)
	{
		tmp = NULL;
		if (f(&tmp, map_get(src, i)) == MAP_STOP)
			return (i);
		map_add_last(dst, tmp);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_WRITE
**
**	Write contents from `src` to `dst`. Function `f` is a user specified
**	function which handles reading the data correctly, allocating space for it
**	and copying it. If a live pointer is returned from `f`, it is added
**	`dst`.
**
**  ----------------------------------------------------------------------------
*/
