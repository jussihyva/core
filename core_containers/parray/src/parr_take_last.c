/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_take_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/15 15:48:02 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*parr_take_last(t_parray *arr)
{
	void	*out;

	if (parr_null(arr))
		return (NULL);
	out = parr_get_last(arr);
	if (!(parr_del_last(arr)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_TAKE_LAST
**
**	Take the last element from an array. Contrary to get, take also
**	removes the element from the array.
**
**  ----------------------------------------------------------------------------
*/
