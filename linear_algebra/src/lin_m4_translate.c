/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_m4_translate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:36:23 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 00:24:55 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lin.h"

t_mat4	lin_m4_translate(t_vec4 *src)
{
	t_mat4	out;

	out = lin_m4_id();
	out.m[3] = src->v[0];
	out.m[7] = src->v[1];
	out.m[11] = src->v[2];
	out.m[15] = src->v[3];
	return (out);
}

/*
**  ----------------------------------------------------------------------------
**
**	Create a transformatio matrix from `src`.
**
**  ----------------------------------------------------------------------------
*/