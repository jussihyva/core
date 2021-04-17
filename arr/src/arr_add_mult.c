/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_add_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/17 18:09:07 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

ssize_t		arr_add_mult(t_arr *arr, size_t count, ...)
{
	va_list	ap;

	va_start(ap, count);
	while (count--)
	{
		if (!(arr_add_last(arr, va_arg(ap, void *))))
			return (ARR_FAIL);
	}
	va_end(ap);
	return ((ssize_t)arr->count);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_ADD_MULT
**
**	Add `count` members to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
