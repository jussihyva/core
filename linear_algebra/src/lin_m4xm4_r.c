/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_mul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 00:29:38 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lin.h"

t_mat4	lin_m4xm4_r(t_mat4 *a, t_mat4 *b)
{
	t_mat4	c;
	uint8_t	i;
	uint8_t	j;

	i = 0;
	j = 0;
	while (i < 16)
	{
		c.m[0 + i] = a->m[0] * b->m[0 + j] + a->m[1] * b->m[4 + j]
			+ a->m[2] * b->m[8 + j] + a->m[3] * b->m[12 + j];
		c.m[1 + i] = a->m[4] * b->m[0 + j] + a->m[5] * b->m[4 + j]
			+ a->m[6] * b->m[8 + j] + a->m[7] * b->m[12 + j];
		c.m[2 + i] = a->m[8] * b->m[0 + j] + a->m[9] * b->m[4 + j]
			+ a->m[10] * b->m[8 + j] + a->m[11] * b->m[12 + j];
		c.m[3 + i] = a->m[12] * b->m[0 + j] + a->m[13] * b->m[4 + j]
			+ a->m[14] * b->m[8 + j] + a->m[15] * b->m[12 + j];
		j += 1;
		i += 4;
	}
	return (c);
}
