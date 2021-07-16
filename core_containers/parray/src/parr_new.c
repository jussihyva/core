/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:25:36 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/core.h"

t_ret	parr_new(t_parray *src, t_size size)
{
	src->size = size;
	src->len = 0;
	src->data = (void **)malloc(sizeof(void *) * size);
	if (!src->data)
		return (CR_ERROR_MALLOC);
	return (CR_SUCCESS);
}

/*
**  ----------------------------------------------------------------------------
**
**	Parr
**
**	Allocate a new dynamic array. You can pass any starting size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
