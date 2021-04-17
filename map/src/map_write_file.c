/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_write_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:40:09 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

static int		deallocate_str(void **data, size_t i)
{
	free(*data);
	*data = NULL;
	return (i);
}

static int		write_file(FILE *file, t_map *prepend,
				int (*f)(void **, void *))
{
	size_t		i;
	char		*line;

	i = 0;
	while (i < prepend->len)
	{
		line = NULL;
		if (f == MAP_STRING)
			line = (char *)prepend->data[i];
		else
			f((void **)&line, prepend->data[i]);
		if (!(fprintf(file, "%s\n", line)))
			return (MAP_FAIL);
		i++;
	}
	map_iterate(prepend, deallocate_str);
	return (1);
}

int				map_write_file(char *dst, t_map *src, ssize_t flag,
				int (*f)(void **, void *))
{
	FILE		*file;
	t_map		prepend;
	size_t		i;

	i = 0;
	if (map_null(src))
		return (MAP_FAIL);
	prepend = map_new(1);
	if (flag == MAP_PREPEND)
		if (!(map_read_file(&prepend, dst)))
			return (MAP_FAIL);
	if ((flag == MAP_WRITE || flag == MAP_PREPEND) && !(file = fopen(dst, "w")))
		return (MAP_FAIL);
	else if (flag == MAP_APPEND && !(file = fopen(dst, "a")))
		return (MAP_FAIL);
	if (!(write_file(file, src, f)))
		return (MAP_FAIL);
	if (flag == MAP_PREPEND)
		if (!(write_file(file, &prepend, f)))
			return (MAP_FAIL);
	map_free(&prepend);
	fclose(file);
	return (src->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	MAP_WRITE_FILE
**
**	Read each line of a file into an array. If filename is NULL, reads from
**	fd 0 (stdin).
**
**  ----------------------------------------------------------------------------
*/
