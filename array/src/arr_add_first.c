/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_first.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 18:19:14 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_add_first(t_arr *arr, void *data)
{
	if (!(arr_add(arr, data, 0)))
		return (CR_FAIL);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD_FIRST
**
**	Add a new member to the beginning of a dynamic string. If the string is not
**	sufficiently big a new memory area double the alloc_size of the previous one
**	is allocated. One extra member is added to the allocation for the case
**	that the string has alloc_size 0.
**
**  ----------------------------------------------------------------------------
*/
