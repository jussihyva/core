/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 02:28:23 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../inc/core.h"

ssize_t	parr_add_mult(t_parray *arr, size_t len, ...)
{
	va_list	ap;

	va_start(ap, len);
	while (len--)
	{
		if (!(parr_add_last(arr, va_arg(ap, void *))))
			return (CR_FAIL);
	}
	va_end(ap);
	return (arr->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_MULT
**
**	Add `len` members to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
