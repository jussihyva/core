/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_read_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/12 11:22:01 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_read_file(t_parray *dst, char *filename)
{
	char	*line;
	ssize_t	fd;
	ssize_t	ret;

	if (parr_null(dst))
		return (CR_FAIL);
	if (filename == NULL)
		return (CR_FAIL);
	if (!(fd = open(filename, O_RDONLY)))
		return (CR_FAIL);
	line = NULL;
	while ((ret = s_readline(fd, &line)))
		if (!(parr_add_last(dst, line)))
			return (CR_FAIL);
	close(fd);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_READ_FILE
**
**	Read each line of a file into an array. If filename is NULL, reads from
**	fd 0 (stdin).
**
**  ----------------------------------------------------------------------------
*/
