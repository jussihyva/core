/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_take.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:09:12 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 17:55:34 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

void	*parr_take(t_parray *arr, size_t index)
{
	void	*out;

	if (index > arr->len || parr_null(arr))
		return (NULL);
	out = parr_get(arr, index);
	if (!(parr_del(arr, index)))
		return (NULL);
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_TAKE
**
**	Take a member from a dynamic array at `index`. Contrary to get, take also
**	removes the member from the array.
**
**  ----------------------------------------------------------------------------
*/
