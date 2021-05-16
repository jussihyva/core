/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_v4_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/17 02:24:53 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/core.h"

ssize_t	lin_v4_print(void *elem, size_t i)
{
	t_vec4	*src;

	src = elem;
	print("[%zu] {%.2lf}{%.2lf}{%.2lf}{%.2lf}\n",
		i, src->v[0], src->v[1], src->v[2], src->v[3]);
	return (i);
}
