/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 22:42:01 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

t_arr	arr_new(size_t elem_size)
{
	t_arr	out;

	out.elem_size = elem_size;
	out.len = 0;
	out.alloc_size = 0;
	out.reserv_size = 0;
	out.data = NULL;
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_NEW
**
**	Allocate a new dynamic array. You can pass any starting alloc_size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
