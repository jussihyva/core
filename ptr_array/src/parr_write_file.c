/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_write_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/07 16:10:42 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

static
ssize_t	deallocate_str(void *data, size_t i)
{
	free(data);
	return (i);
}

static
ssize_t	write_file(FILE *file, t_parray *prepend,
		ssize_t (*f)(void *, void *))
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < prepend->len)
	{
		line = NULL;
		if (f == CR_STRING)
			line = (char *)prepend->data[i];
		else
			f((void *)line, prepend->data[i]);
		if (line)
		{
			if (!(fprintf(file, "%s\n", line)))
				return (CR_FAIL);
		}
		i++;
	}
	parr_iter(prepend, deallocate_str);
	return (1);
}

ssize_t	parr_write_file(char *dst, t_parray *src, ssize_t flag,
		ssize_t (*f)(void *, void *))
{
	FILE	*file;
	t_parray	prepend;

	if (parr_null(src))
		return (CR_FAIL);
	prepend = parr_new(1);
	if (flag == CR_PREPEND)
		if (!(parr_read_file(&prepend, dst)))
			return (CR_FAIL);
	file = fopen(dst, "w");
	if ((flag == CR_WRITE || flag == CR_PREPEND) && !file)
		return (CR_FAIL);
	else if (flag == CR_APPEND && !(file = fopen(dst, "a")))
		return (CR_FAIL);
	if (!(write_file(file, src, f)))
		return (CR_FAIL);
	if (flag == CR_PREPEND)
		if (!(write_file(file, &prepend, f)))
			return (CR_FAIL);
	parr_free(&prepend);
	if (file)
		fclose(file);
	return (src->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_WRITE_FILE
**
**	Read each line of a file into an array. If filename is NULL, reads from
**	fd 0 (stdin).
**
**  ----------------------------------------------------------------------------
*/
