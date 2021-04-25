/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lin_v4_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkoskela <jkoskela@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 00:30:42 by jkoskela          #+#    #+#             */
/*   Updated: 2021/04/25 01:07:38 by jkoskela         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/lin.h"

ssize_t	lin_v4_print(void *elem, size_t i)
{
	t_vec4	*src;

	src = elem;
	printf("%-5.2lf|%-5.2lf|%-5.2lf|%-5.2lf|\n",
			src->v[0], src->v[1], src->v[2], src->v[3]);
	return (i);
}