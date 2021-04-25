/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_iterate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/13 11:24:56 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

int				parr_iterate(t_parr *arr, int (*f)(void **, size_t))
{
	size_t		i;
	int			ret;

	if (parr_null(arr))
		return (CR_FAIL);
	i = 0;
	while (i < arr->len)
	{
		if ((ret = f(&arr->data[i], i)) == CR_STOP)
			return (i);
		i++;
	}
	return (i);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ITERATE
**
**	Iterate a dynamic array and execute a function passed by f on all
**	members.
**
**  ----------------------------------------------------------------------------
*/
