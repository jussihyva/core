/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parr_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/13 21:29:35 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/parr.h"
# include "../../inc/core.h"

t_parray	parr_new(size_t size)
{
	t_parray	out;

	out.size = size;
	out.len = 0;
	out.data = (void **)malloc(sizeof(void *) * size);
	if (!out.data)
	{
		printf("Allocation failed in function: map_new!\n");
		return ((t_parray){NULL, 0, 0});
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
