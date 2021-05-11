/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_v4_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoskine <skoskine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/05/11 09:21:43 by skoskine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lin.h"

ssize_t	lin_v4_print(void *elem, size_t i)
{
	t_vec4	*src;

	src = elem;
	print("[%zu] {%.2lf}{%.2lf}{%.2lf}{%.2lf}\n",
		i, src->v[0], src->v[1], src->v[2], src->v[3]);
	return (i);
}
