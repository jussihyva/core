/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_null.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 23:30:25 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t	arr_null(t_arr *arr)
{
	if (!arr->alloc_size && !arr->reserv_size)
		return (CR_SUCCESS);
	if (!arr->elem_size)
		return (CR_SUCCESS);
	return (CR_FAIL);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_NULL
**
**	Checks if the array is a NULL array.
**
**  ----------------------------------------------------------------------------
*/
