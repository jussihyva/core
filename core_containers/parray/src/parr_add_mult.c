/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_add_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:52:37 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ssize	parr_add_mult(
		t_parray *dst,
		t_size count,
		...)
{
	va_list	ap;
	t_ret	ret;

	va_start(ap, count);
	while (count--)
	{
		ret = parr_add_last(dst, va_arg(ap, void *));
		if (ret < 0)
			return (ret);
	}
	va_end(ap);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_ADD_MULT
**
**	Add `len` elements to a dynamic array.
**
**  ----------------------------------------------------------------------------
*/
