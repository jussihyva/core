/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_grow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/07/16 15:31:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_grow(t_parray *arr, t_size new_size)
{
	t_parray	out;
	t_ret		ret;

	ret = parr_new(&out, new_size);
	if (ret < 0)
		return (ret);
	if (parr_null(&out))
		return (CR_ERROR_INPUT);
	out.len = arr->len;
	ret = parr_copy(&out, arr);
	if (ret < 0)
		return (ret);
	parr_free(arr);
	*arr = out;
	return (out.size);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_GROW
**
**	Increase the size of the array.
**
**  ----------------------------------------------------------------------------
*/
