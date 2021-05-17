/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_v4_dot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/24 21:36:44 by julius           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

double	lin_v4_dot(t_vec4 *a, t_vec4 *b)
{
	return ((a->v[0] * b->v[0])
		+ (a->v[1] * b->v[1])
		+ (a->v[2] * b->v[2])
		+ (a->v[3]* b->v[3]));
}
