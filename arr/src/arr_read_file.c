/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_read_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_read_file(t_arr *dst, char *filename)
{
	char	c[1];
	int		fd;
	ssize_t	ret;

	if (arr_null(dst)
		|| filename == NULL
		|| !(fd = open(filename, O_RDONLY)))
		return (CR_FAIL);
	while ((ret = read(fd, c, 1)) > 0)
		if (!(arr_add_last(dst, c)))
			return (CR_FAIL);
	close(fd);
	return ((ssize_t)dst->count);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_READ_FILE
**
**	Read each line of a file into an array. If filename is NULL, reads from
**	fd 0 (stdin).
**
**  ----------------------------------------------------------------------------
*/
