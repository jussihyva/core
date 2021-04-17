/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_write.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 18:12:41 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

static ssize_t	arr_write_string(t_arr *dst, t_arr *src)
{
	size_t		i;
	char		*tmp;

	i = 0;
	while (i < src->count)
	{
		tmp = arr_get(src, i);;
		arr_add_last(dst, s_dup(tmp));
		i++;
	}
	return ((ssize_t)i);
}

ssize_t		arr_write(t_arr *dst, t_arr *src,
			ssize_t (*f)(void *, void *))
{
	size_t	i;
	void	*tmp;

	i = 0;
	if (f == ARR_STRING)
		return (arr_write_string(dst, src));
	while (i < src->count)
	{
		tmp = NULL;
		if (f(&tmp, arr_get(src, i)) == ARR_STOP)
			return ((ssize_t)i);
		arr_add_last(dst, tmp);
		i++;
	}
	return ((ssize_t)i);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_WRITE
**
**	Write contents from `src` to `dst`. Function `f` is a user specified
**	function which handles reading the data correctly, allocating space for it
**	and copying it. If a live pointer is returned from `f`, it is added
**	`dst`.
**
**  ----------------------------------------------------------------------------
*/
