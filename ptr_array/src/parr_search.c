/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 17:50:41 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/core.h"

ssize_t	parr_search(t_parray *dst, t_parray *src, void *key,
		void *(*f)(void *, void *))
{
	void	*data;
	size_t	i;

	i = 0;
	data = NULL;
	while (1)
	{
		if (i == src->len)
			break ;
		data = parr_get(src, i);
		data = f(key, data);
		if (data)
		{
			if (!(parr_add_last(dst, data)))
				return (CR_FAIL);
		}
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_SEARCH
**
**	Search from an array by passing a key and a selection function. In the
**	selection function user can put any logic and anything returned from
**	the selection function is put into the array `dst` passed as an argument.
**
**  ----------------------------------------------------------------------------
*/
