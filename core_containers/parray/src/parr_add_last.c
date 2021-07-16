/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_last.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:52:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_add_last(
		t_parray *arr,
		void *data)
{
	t_ret	ret;

	if (parr_null(arr) || !data)
		return (CR_ERROR_INPUT);
	if (arr->len == arr->size)
	{
		ret = parr_grow(arr, (arr->size + 1) * 2);
		if (ret < 0)
			return (ret);
	}
	arr->data[arr->len] = data;
	arr->len++;
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_LAST
**
**	Add a new element to the end of a dynamic string. If the string is not
**	sufficiently big a new memory area double the size of the previous one
**	is allocated. One extra element is added to the allocation for the case
**	that the string has size 0.
**
**  ----------------------------------------------------------------------------
*/
