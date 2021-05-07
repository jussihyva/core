/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_write.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:41:19 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

static
ssize_t	parr_write_string(t_parray *dst, t_parray *src)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (i < src->len)
	{
		tmp = src->data[i];
		parr_add_last(dst, s_dup(tmp));
		i++;
	}
	return (i);
}

ssize_t	parr_write(t_parray *dst, t_parray *src, ssize_t (*f)(void *, void *))
{
	size_t	i;
	void	*tmp;

	i = 0;
	if (f == CR_STRING)
		return (parr_write_string(dst, src));
	while (i < src->len)
	{
		tmp = NULL;
		if (f(tmp, parr_get(src, i)) == CR_STOP)
			return (i);
		parr_add_last(dst, tmp);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_WRITE
**
**	Write contents from `src` to `dst`. Function `f` is a user specified
**	function which handles reading the data correctly, allocating space for it
**	and copying it. If a live pointer is returned from `f`, it is added
**	`dst`.
**
**  ----------------------------------------------------------------------------
*/
