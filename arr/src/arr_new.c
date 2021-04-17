/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_new.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 01:31:09 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/15 10:42:52 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/arr.h"

t_arr			arr_new(size_t arr_size, size_t m_size)
{
	t_arr		out;

	out.size = arr_size;
	out.memsize = m_size;
	out.count = 0;
	if (!(out.data = (uint8_t *)malloc(m_size * arr_size)))
	{
		perror("Array allocation failed in arr_new!\n");
		return ((t_arr){NULL, 0, 0, 0});
	}
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	ARR_NEW
**
**	Allocate a new dynamic array. You can pass any starting size and resizing
**	will be hanled automatically. A better initial size approximation leads to
**	fewer resizes.
**
**  ----------------------------------------------------------------------------
*/
