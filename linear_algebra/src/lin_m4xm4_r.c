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

	c.m[0] = a->m[0] * b->m[0] + a->m[1] * b->m[1]
	+ a->m[2] * b->m[2] + a->m[3] * b->m[3];
	c.m[1] = a->m[4] * b->m[0] + a->m[5] * b->m[1]
	+ a->m[6] * b->m[2] + a->m[7] * b->m[3];
	c.m[2] = a->m[8] * b->m[0] + a->m[9] * b->m[1]
	+ a->m[10] * b->m[2] + a->m[11] * b->m[3];
	c.m[3] = a->m[12] * b->m[0] + a->m[13] * b->m[1]
	+ a->m[14] * b->m[2] + a->m[15] * b->m[3];

	c.m[4] = a->m[0] * b->m[4] + a->m[1] * b->m[5]
	+ a->m[2] * b->m[6] + a->m[3] * b->m[7];
	c.m[5] = a->m[4] * b->m[4] + a->m[5] * b->m[5]
	+ a->m[6] * b->m[6] + a->m[7] * b->m[7];
	c.m[6] = a->m[8] * b->m[4] + a->m[9] * b->m[5]
	+ a->m[10] * b->m[6] + a->m[11] * b->m[7];
	c.m[7] = a->m[12] * b->m[4] + a->m[13] * b->m[5]
	+ a->m[14] * b->m[6] + a->m[15] * b->m[7];

	c.m[8] = a->m[0] * b->m[8] + a->m[1] * b->m[9]
	+ a->m[2] * b->m[10] + a->m[3] * b->m[11];
	c.m[9] = a->m[4] * b->m[8] + a->m[5] * b->m[9]
	+ a->m[6] * b->m[10] + a->m[7] * b->m[11];
	c.m[10] = a->m[8] * b->m[8] + a->m[9] * b->m[9]
	+ a->m[10] * b->m[10] + a->m[11] * b->m[11];
	c.m[11] = a->m[12] * b->m[8] + a->m[13] * b->m[9]
	+ a->m[14] * b->m[10] + a->m[15] * b->m[11];

	c.m[12] = a->m[0] * b->m[12] + a->m[1] * b->m[13]
	+ a->m[2] * b->m[14] + a->m[3] * b->m[15];
	c.m[13] = a->m[4] * b->m[12] + a->m[5] * b->m[13]
	+ a->m[6] * b->m[14] + a->m[7] * b->m[15];
	c.m[14] = a->m[8] * b->m[12] + a->m[9] * b->m[13]
	+ a->m[10] * b->m[14] + a->m[11] * b->m[15];
	c.m[15] = a->m[12] * b->m[12] + a->m[13] * b->m[13]
	+ a->m[14] * b->m[14] + a->m[15] * b->m[15];

	return (c);
}

/*t_mat4	lin_m4_multrow(t_mat4 a, t_mat4 b)*/
/*{*/
	/*t_mat4	c;*/

	/*c->m[0] = lin_v4_dot(lin_m4_getrow(a, 0), lin_m4_getrow(b, 0));*/
	/*c->m[1] = lin_v4_dot(lin_m4_getrow(a, 1), lin_m4_getrow(b, 0));*/
	/*c->m[2] = lin_v4_dot(lin_m4_getrow(a, 2), lin_m4_getrow(b, 0));*/
	/*c->m[3] = lin_v4_dot(lin_m4_getrow(a, 3), lin_m4_getrow(b, 0));*/

	/*c->m[4] = lin_v4_dot(lin_m4_getrow(a, 0), lin_m4_getrow(b, 1));*/
	/*c->m[5] = lin_v4_dot(lin_m4_getrow(a, 1), lin_m4_getrow(b, 1));*/
	/*c->m[6] = lin_v4_dot(lin_m4_getrow(a, 2), lin_m4_getrow(b, 1));*/
	/*c->m[7] = lin_v4_dot(lin_m4_getrow(a, 3), lin_m4_getrow(b, 1));*/

	/*c->m[8] = lin_v4_dot(lin_m4_getrow(a, 0), lin_m4_getrow(b, 2));*/
	/*c->m[9] = lin_v4_dot(lin_m4_getrow(a, 1), lin_m4_getrow(b, 2));*/
	/*c->m[10] = lin_v4_dot(lin_m4_getrow(a, 2), lin_m4_getrow(b, 2));*/
	/*c->m[11] = lin_v4_dot(lin_m4_getrow(a, 3), lin_m4_getrow(b, 2));*/

	/*c->m[12] = lin_v4_dot(lin_m4_getrow(a, 0), lin_m4_getrow(b, 3));*/
	/*c->m[13] = lin_v4_dot(lin_m4_getrow(a, 1), lin_m4_getrow(b, 3));*/
	/*c->m[14] = lin_v4_dot(lin_m4_getrow(a, 2), lin_m4_getrow(b, 3));*/
	/*c->m[15] = lin_v4_dot(lin_m4_getrow(a, 3), lin_m4_getrow(b, 3));*/

	/*return (c);*/
/*}*/

