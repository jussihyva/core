/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/13 13:09:15 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"

t_parr	parr_new(size_t size)
{
	t_parr	out;

	out.size = size;
	out.len = 0;
	if (!(out.data = (void **)malloc(sizeof(void *) * size)))
	{
		perror("Array allocation failed in parr_new!\n");
		return ((t_parr){NULL, 0, 0});
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	PARR_NEW
**
**	Allocate a new dynamic array. You can pass any starting size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
