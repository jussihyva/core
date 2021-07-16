/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:59:21 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_del(
		t_parray *arr,
		t_size index)
{
	t_size	i;

	if (parr_null(arr))
		return (CR_ERROR_INPUT);
	if (arr->len == 0 || index > arr->len)
		return (CR_ERROR_BOUNDS);
	i = index;
	while (i < arr->len - 1)
	{
		arr->data[i] = arr->data[i + 1];
		i++;
	}
	arr->len--;
	return (arr->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_DEL
**
**	Delete a element at `index` from a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
