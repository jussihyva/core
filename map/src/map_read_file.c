/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/12 11:22:01 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int				map_read_file(t_map *dst, char *filename)
{
	char		*line;
	int			fd;
	int			ret;

	if (map_null(dst))
		return (MAP_FAIL);
	if (filename == NULL)
		return (MAP_FAIL);
	if (!(fd = open(filename, O_RDONLY)))
		return (MAP_FAIL);
	line = NULL;
	while ((ret = s_readline(fd, &line)))
		if (!(map_add_last(dst, line)))
			return (MAP_FAIL);
	close(fd);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_READ_FILE
**
**	Read each line of a file into an array. If filename is NULL, reads from
**	fd 0 (stdin).
**
**  ----------------------------------------------------------------------------
*/
