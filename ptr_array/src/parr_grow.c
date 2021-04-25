/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_grow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/14 16:17:34 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_grow(t_parr *arr, size_t new_size)
{
	t_parr	out;
	ssize_t	error;

	out = parr_new(new_size);
	if (parr_null(&out))
		return (CR_FAIL);
	out.len = arr->len;
	if (!(error = parr_copy(&out, arr)))
		return (CR_FAIL);
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
