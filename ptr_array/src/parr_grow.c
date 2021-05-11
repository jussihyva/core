/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_grow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:50:44 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

ssize_t	parr_grow(t_parray *arr, size_t new_size)
{
	t_parray	out;
	ssize_t		error;

	out = parr_new(new_size);
	if (parr_null(&out))
		return (CR_FAIL);
	out.len = arr->len;
	error = parr_copy(&out, arr);
	if (!error)
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
