/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_search.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/18 14:49:43 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_search(t_arr *src, t_arr *key)
{
	void	*value;
	ssize_t	ret;
	size_t	i;

	if (arr_null(src)
		|| (ret = arr_find(src, key->data)) < 0)
		return (CR_FAIL);
	i = (size_t)ret;
	while (1)
	{
		if (i == src->count)
			break ;
		value = arr_get(src, i);
		if (mem_cmp(key->data, value, key->count * key->memsize) == 0)
			return ((ssize_t)i);
		i++;
	}
	return (CR_EMPTY);
}

/*
**  ----------------------------------------------------------------------------
**
**	CR_SEARCH
**
**	Search from an array by passing a key and a selection function. In the
**	selection function user can put any logic and anything returned from
**	the selection function is put into the array `dst` passed as an argument.
**
**  ----------------------------------------------------------------------------
*/
