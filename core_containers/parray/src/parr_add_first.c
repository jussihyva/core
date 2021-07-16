/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:53:03 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_add_first(
		t_parray *arr,
		void *data)
{
	t_ret	ret;

	ret = parr_add(arr, data, 0);
	if (ret < 0)
		return (ret);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_FIRST
**
**	Add a new element to the beginning of a dynamic string. If the string is not
**	sufficiently big a new memory area double the size of the previous one
**	is allocated. One extra element is added to the allocation for the case
**	that the string has size 0.
**
**  ----------------------------------------------------------------------------
*/
