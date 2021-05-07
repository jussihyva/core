/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_del.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:22:49 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_del(t_parray *arr, size_t index)
{
	size_t	i;

	if (parr_null(arr))
		return (CR_FAIL);
	if (index > arr->len)
		return (CR_FAIL);
	i = index;
	while (i < arr->len)
	{
		arr->data[i] = arr->data[i + 1];
		i++;
	}
	arr->len--;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_DEL
**
**	Delete a member at `index` from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
