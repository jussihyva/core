/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 16:13:41 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_join(
		t_parray *dst,
		t_size len,
		...)
{
	va_list		ap;
	t_parray	*tmp;
	t_ret		ret;
	t_size		i;

	va_start(ap, len);
	if (parr_null(dst))
		return (CR_ERROR_INPUT);
	while (len--)
	{
		tmp = va_arg(ap, t_parray *);
		if (parr_null(tmp))
			return (CR_ERROR_INPUT);
		i = 0;
		while (i < tmp->len && tmp->data[i])
		{
			ret = parr_add_last(dst, tmp->data[i]);
			if (ret < 0)
				return (ret);
			i++;
		}
	}
	va_end(ap);
	return (dst->len);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_JOIN
**
**	Join `len` amount of arrays to the source array `dst`.
**
**  ----------------------------------------------------------------------------
*/
