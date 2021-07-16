/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_read_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:23:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_read_file(
		t_parray *dst,
		char *filename)
{
	char	*line;
	t_ssize	fd;
	t_ssize	ret;

	if (parr_null(dst) || filename == NULL)
		return (CR_ERROR_INPUT);
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (CR_ERROR_FILE);
	line = NULL;
	ret = s_readline(fd, &line);
	while (ret)
	{
		if (!(parr_add_last(dst, line)))
			return (CR_FAIL);
		ret = s_readline(fd, &line);
	}
	close(fd);
	if (ret == -1)
		return (CR_ERROR_FILE);
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
