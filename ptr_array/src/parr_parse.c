/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/26 01:39:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_parse(t_parr *dst, t_parr *src,
		ssize_t (*f)(t_parr *, void *))
{
	size_t	i;
	void	*data;

	i = 0;
	if (parr_null(src) || parr_null(dst))
		return (CR_FAIL);
	while (i < src->len)
	{
		data = parr_get(src, i);
		if (!(f(dst, data)))
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_PARSE
**
**	iter array `src` so that for each member a parse function is executed
**	The parse function is user-defined and parses each member so that rersults
**	are added in `dst`.
**
**  ----------------------------------------------------------------------------
*/
