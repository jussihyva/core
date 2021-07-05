/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_take_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/03 01:31:15 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

void	*parr_take_first(t_parray *arr)
{
	void	*out;

	if (parr_null(arr))
		return (NULL);
	out = parr_get_first(arr);
	if (!out)
		return (NULL);
	if (!(parr_del_first(arr)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_TAKE_FIRST
**
**	Take the first rawber from an array. Contrary to get, take also
**	removes the rawber from the array.
**
**  ----------------------------------------------------------------------------
*/
