/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 16:26:55 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/19 04:39:48 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

t_int64	math_log(t_int64 n)
{
	static t_uint64	x = 0x07EDD5E59A4E28C2;
	static int		tab64[64] = {
	63, 0, 58, 1, 59, 47, 53, 2,
	60, 39, 48, 27, 54, 33, 42, 3,
	61, 51, 37, 40, 49, 18, 28, 20,
	55, 30, 34, 11, 43, 14, 22, 4,
	62, 57, 46, 52, 38, 26, 32, 41,
	50, 36, 17, 19, 29, 10, 13, 21,
	56, 45, 25, 31, 35, 16, 9, 12,
	44, 24, 15, 8, 23, 7, 6, 5};

	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n |= n >> 32;
	return (tab64[((t_uint64)((n - (n >> 1)) * x)) >> 58]);
}

/*
**  ----------------------------------------------------------------------------
**
**	math_log
**
**	Calculate the base 2 logarithm of n.
**
**  ----------------------------------------------------------------------------
*/
