/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/20 21:57:40 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_del(t_parray *arr, t_size index)
{
	t_size	i;

	if (parr_null(arr))
		return (CR_FAIL);
	if (index > arr->len)
		return (CR_FAIL);
	i = index;
	while (i < arr->len - 1)
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