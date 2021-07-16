/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:54:31 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_assign(
		t_parray *arr,
		void **src,
		t_size size)
{
	t_ret	ret;
	t_size	i;

	i = 0;
	if (parr_null(arr) || !src)
		return (CR_ERROR_INPUT);
	while (i < size)
	{
		ret = parr_add_last(arr, src[i]);
		if (ret < 0)
			return (ret);
		i++;
	}
	return (arr->size);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ASSIGN
**
**	Assign an array of pointer of known size to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
