/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_find.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/20 19:35:57 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_find(t_arr *src, void *key)
{
	void	*value;
	size_t	i;

	if (arr_null(src))
		return (CR_FAIL);
	i = 0;
	while (1)
	{
		if (i == src->len)
			break ;
		value = arr_get(src, i);
		if (mem_cmp(key, value, src->elem_size) == 0)
			return ((ssize_t)i);
		i++;
	}
	return (CR_EMPTY);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_FIND
**
**	Search from an array by passing a key and a selection function. In the
**	selection function user can put any logic and anything returned from
**	the selection function is returned as a void pointer.
**
**  ----------------------------------------------------------------------------
*/
